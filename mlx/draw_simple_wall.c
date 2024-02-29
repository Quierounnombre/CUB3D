/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_simple_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:09:11 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/29 14:14:44 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_simple_wall(t_cube *cube, int column, double wall_height)
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
