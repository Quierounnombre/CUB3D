/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:19 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/29 16:05:02 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_wall(t_ray_info *ray, t_cube *cube)
{
	if (ray->dir == UNDEFINE_DIR)
		draw_simple_wall(cube, ray->column, ray->wall_height);
	if (ray->dir == NORTH)
		draw_texture(ray, cube, &(cube->map->north));
	if (ray->dir == SOUTH)
		draw_texture(ray, cube, &(cube->map->south));
	if (ray->dir == EAST)
		draw_texture(ray, cube, &(cube->map->east));
	if (ray->dir == WEST)
		draw_texture(ray, cube, &(cube->map->west));
}
