/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:00:08 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 16:27:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	put_texture_pixel(t_cube *cube, t_texture *texture,
			double pos_to_draw, t_vector2D pos)
{
	int			column;
	t_color		color;
	t_vector2D	wall_ratios;

	column = pos.x;
	wall_ratios = calc_wall_ratios(texture, pos);
	color = get_color_in_texture(texture, wall_ratios, pos);
	mlx_point_draw(cube, column, pos_to_draw, color);
}
