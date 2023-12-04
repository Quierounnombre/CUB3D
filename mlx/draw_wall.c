/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 17:23:19 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

#define SPLIT_THE_WIN 2

void	draw_wall(double wall_height, int column, t_cube *cube)
{
	double	window_dimension;
	int		i;

	window_dimension = (HEIGHT - wall_height) / SPLIT_THE_WIN;
	i = window_dimension;
	window_dimension += wall_height;
	while (i < window_dimension)
	{
		mlx_point_draw(cube, column, i, cube->map->texture.wall_color);
		i++;
	}
}
