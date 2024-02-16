/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/16 13:24:57 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	dda(t_cube *cube, t_ray *ray)
{
	while (ray->hit == 0 && ray->map_cor.x < cube->map->height
		&& cube->map->width)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map_cor.x += ray->step.x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map_cor.y += ray->step.y;
			ray->side_hit = 1;
		}
		if (cube->map->map[ray->map_cor.x][ray->map_cor.y] > 0)
			ray->hit = 1;
	}
}
