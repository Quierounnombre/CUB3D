/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:31:20 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 16:48:20 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_color	get_color_in_texture(t_texture *texture, t_vector2D wall_ratios,
			t_vector2D pos)
{
	double		height_ratio;
	double		width_ratio;
	int			target_addres;
	int			raw_color;
	t_color		result;

	height_ratio = wall_ratios.x;
	width_ratio = wall_ratios.y;
	target_addres = ((int)height_ratio * pos.x) * ((int)width_ratio * pos.y);
	raw_color = (unsigned int)texture->img->adres + target_addres;
	result = int_to_t_color(raw_color);
	return (result);
}
