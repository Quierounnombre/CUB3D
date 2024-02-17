/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:17:27 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 16:45:08 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_texture(double wall_height, t_cube *cube, t_texture *texture,
			t_vector2D pos_in_txt)
{
	int		column;
	double	window_dimension;
	int		start_of_draw;
	int		end_of_draw;

	column = pos_in_txt.x;
	window_dimension = (HEIGHT - wall_height) / SPLIT_THE_WIN;
	start_of_draw = window_dimension;
	end_of_draw = window_dimension + wall_height;
	while (start_of_draw <= end_of_draw)
	{
		put_texture_pixel(cube, texture, start_of_draw, pos_in_txt);
		start_of_draw++;
	}
}
