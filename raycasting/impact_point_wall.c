/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_point_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/17 17:46:34 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

double determine_impact_point(t_ray *ray, t_cube *cube)
{
	double	impact;

	if (ray->side_hit == 0)
		impact = cube->player->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		impact = cube->player->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	return (impact);
}