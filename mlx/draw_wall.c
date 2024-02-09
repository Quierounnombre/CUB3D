/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:19 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/09 11:17:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_wall(double wall_height, int column, t_cube *cube, t_direction dir)
{

	if (dir == UNDEFINE_DIR)
		draw_simple_wall(cube, column, wall_height);
	if (dir == NORTH)
		draw_texture();
	if (dir == SOUTH)
		draw_texture();
	if (dir == EAST)
		draw_texture();
	if (dir == WEST)
		draw_texture();
}
