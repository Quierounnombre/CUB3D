/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/19 18:20:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static int	get_texture_height(t_cube *cube, t_direction dir)
{
	if (dir == NORTH)
		return (cube->map->north.height);
	if (dir == SOUTH)
		return (cube->map->south.height);
	if (dir == WEST)
		return (cube->map->west.height);
	if (dir == EAST)
		return (cube->map->east.height);
	return (1);
}

t_ray_info	init_ray_info(t_ray *ray, int colum, t_cube *cube)
{
	t_ray_info	ray_info;
	int			texture_height;

	ray_info.column = colum;
	ray_info.dir = ray->wall_hit;
	ray_info.wall_height = ray->line_height;
	texture_height = get_texture_height(cube, ray_info.dir);
	ray_info.wall_ratios.y = ray->impact_pt - (int)ray->impact_pt;
	ray_info.wall_ratios.x = texture_height / ray_info.wall_height;
	return (ray_info);
}
