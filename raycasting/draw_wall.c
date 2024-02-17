/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:19 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/15 17:51:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_wall(double wall_height, t_vector2D pos_in_txt, t_cube *cube,
		t_direction dir)
{

	if (dir == UNDEFINE_DIR)
		draw_simple_wall(cube, pos_in_txt.x, wall_height);
	if (dir == NORTH)
		draw_texture(wall_height, cube, &(cube->map->north), pos_in_txt);
	if (dir == SOUTH)
		draw_texture(wall_height, cube, &(cube->map->south), pos_in_txt);
	if (dir == EAST)
		draw_texture(wall_height, cube, &(cube->map->east), pos_in_txt);
	if (dir == WEST)
		draw_texture(wall_height, cube, &(cube->map->west), pos_in_txt);
}
