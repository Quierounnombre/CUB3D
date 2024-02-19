/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/17 16:57:19 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	calc_dir_ray(t_cube *cube, t_ray *ray, double camera_pos)
{
	ray->ray_dir.x = cube->player->dir.x + cube->player->plane.x * camera_pos;
	ray->ray_dir.y = cube->player->dir.y + cube->player->plane.y * camera_pos;
}

static void	calc_pos_ray_map(t_cube *cube, t_ray *ray)
{
	ray->map_cor.x = (int)cube->player->pos.x;
	ray->map_cor.y = (int)cube->player->pos.y;
}

static void	init_dda_delta_dist(t_ray *ray)
{
	if (ray->ray_dir.x == 0)
		ray->delta.x = BIG_NUM;
	else
		ray->delta.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta.y = BIG_NUM;
	else
		ray->delta.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

t_ray	*init_ray(t_cube *cube, int x)
{
	t_ray	*ray;
	double	camera_pos;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		exit_error(ERROR_MALLOC, errno, cube);
	camera_pos = 2 * x / (double)WIDTH - 1;
	calc_dir_ray(cube, ray, camera_pos);
	calc_pos_ray_map(cube, ray);
	init_dda_delta_dist(ray);
	return (ray);
}