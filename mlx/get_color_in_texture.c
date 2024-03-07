/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:31:20 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/07 17:26:32 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_color	get_color_in_texture(t_texture *texture, t_ray_info *ray)
{
	t_vector2Dint	pos_texture;
	int				raw_color;
	t_color			result;

	pos_texture.y = ray->wall_ratios.x * texture->height;
	if (ray->dir != 'S' && ray->dir != 'W')
		pos_texture.x = ray->wall_ratios.y * texture->height;
	else
		pos_texture.x = (1 - ray->wall_ratios.y) * texture->height;
	raw_color = *(unsigned int *)(texture->img->adres
			+ (pos_texture.x * (texture->img->bits_per_pixel / 8)
				+ (pos_texture.y * texture->img->line)));
	result = int_to_t_color(raw_color);
	return (result);
}
