/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 17:50:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

#define SPLIT_THE_WIN 2

void	draw_wall(double wall_height, int column, t_cube *cube)
{
	double	window_dimension;
	int		start_of_draw;
	int		end_of_draw;

	window_dimension = (HEIGHT - wall_height) / SPLIT_THE_WIN;
	start_of_draw = window_dimension;
	end_of_draw = window_dimension + wall_height;
	while (start_of_draw <= end_of_draw)
	{
		mlx_point_draw(cube, column, start_of_draw,
			cube->map->wall_color);
		start_of_draw++;
	}
}
