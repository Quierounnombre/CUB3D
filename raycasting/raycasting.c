/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/19 17:56:45 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	calc_initial_side_dist(t_cube *cube, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (cube->player->pos.x - ray->map_cor.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_cor.x + 1.0 - cube->player->pos.x)
			* ray->delta.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (cube->player->pos.y - ray->map_cor.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_cor.y + 1.0 - cube->player->pos.y)
			* ray->delta.y;
	}
}

static void	determine_cardinal_direction(t_ray *ray)
{
	if (ray->side_hit == 0)
	{
		if (ray->ray_dir.x > 0)
			ray->wall_hit = EAST;
		else
			ray->wall_hit = WEST;
	}
	else
	{
		if (ray->ray_dir.y > 0)
			ray->wall_hit = SOUTH;
		else
			ray->wall_hit = NORTH;
	}
}

void	raycasting(t_cube *cube)
{
	int			x;
	t_ray		*ray;
	t_ray_info	ray_info;

	x = 0;
	while (x < WIDTH)
	{
		ray = init_ray(cube, x);
		calc_initial_side_dist(cube, ray);
		dda(cube, ray);
		determine_cardinal_direction(ray);
		ray->perp_wall_dist = calc_perp_wall_dist(ray);
		ray->line_height = (int)calc_wall_height(ray->perp_wall_dist);
		ray->impact_pt = determine_impact_point(ray, cube);
		ray_info = init_ray_info(ray, x, cube);
		draw_wall(&ray_info, cube);
		free(ray);
		x++;
	}
}
