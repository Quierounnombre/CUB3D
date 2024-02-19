/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/19 15:59:44 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_ray_info	init_ray_info(t_ray *ray, int colum)
{
	t_ray_info	ray_info;

	ray_info.column = colum;
	ray_info.dir = ray->wall_hit;
	ray_info.wall_height = ray->line_height;
	ray_info.wall_ratios.y = ray->impact_pt - (int)ray->impact_pt;
	return (ray_info);
}