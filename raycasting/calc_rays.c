/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_hit_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:10 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_ray	*init_ray(t_cube	*cube, int x)
{
	t_ray	*ray;
	double	camera_x;

	ray = (t_ray *)malloc(sizeof(t_ray));
	camera_x = 2 * x / (double)WIDTH - 1;
	if (!ray)
		exit_error(ERROR_MALLOC, errno, cube);
	ray->ray_dir_x = cube->player->dir.x + cube->player->plane.x * camera_x;
	ray->ray_dir_y = cube->player->dir.y + cube->player->plane.y * camera_x;
	ray->map_x = (int)cube->player->pos.x;
	ray->map_y = (int)cube->player->pos.y;
	if (ray->ray_dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	return (ray);
}

void	calc_initial_side_dist(t_cube *cube, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (cube->player->pos.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - cube->player->pos.x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (cube->player->pos.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - cube->player->pos.y) * ray->delta_y;
	}
}

void	dda(t_cube *cube, t_ray *ray)
{
	while (ray->hit == 0 && ray->map_x < cube->map->height && cube->map->width)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cube->map->map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

void	raycasting(t_cube *cube)
{
	int		x;
	t_ray	*ray;
	int		draw_start;
	int		draw_end;

	x = -1;
	while (++x < WIDTH)
	{
		ray = init_ray(cube, x);
		calc_initial_side_dist(cube, ray);
		dda(cube, ray);
		if (ray->side == 0)
			ray->perp_wall_dist = (ray->side_x - ray->delta_x);
		else
			ray->perp_wall_dist = (ray->side_y - ray->delta_y);
		ray->line_height = (int)calc_wall_height(ray->perp_wall_dist);
		draw_start = (((-1) * (ray->line_height)) / 2) + (HEIGHT / 2);
		if (draw_start < 0)
			draw_start = 0;
		draw_end = ray->line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		draw_wall(draw_end - draw_start, x, cube);
		free(ray);
	}
}
