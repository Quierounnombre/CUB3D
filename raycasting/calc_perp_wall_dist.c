/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_perp_wall_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:00 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 17:11:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

double	calc_perp_wall_dist(t_ray *ray)
{
	double	perp_wall_dist;

	if (ray->side_hit == 0)
		perp_wall_dist = (ray->side.x - ray->delta.x);
	else
		perp_wall_dist = (ray->side.y - ray->delta.y);
	return (perp_wall_dist);
}
