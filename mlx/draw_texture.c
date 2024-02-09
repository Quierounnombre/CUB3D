/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:17:27 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/09 11:31:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_texture(double wall_height, t_cube *cube, t_texture *texture,
			int column)
{
	double	window_dimension;
	int		start_of_draw;
	int		end_of_draw;
	t_color	color;

	window_dimension = (HEIGHT - wall_height) / SPLIT_THE_WIN;
	start_of_draw = window_dimension;
	end_of_draw = window_dimension + wall_height;
	while (start_of_draw <= end_of_draw)
	{
		color = get_next_color_in_texture();
		mlx_point_draw(cube, column, start_of_draw,
			color);
		start_of_draw++;
	}
}
