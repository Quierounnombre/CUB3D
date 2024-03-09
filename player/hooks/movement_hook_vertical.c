/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hook_vertical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:42 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/09 12:46:54 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static void	change_map_pos(t_vector2D pos, t_vector2D dir, t_cube *cube)
{
	if (!cube->map->map[(int)(pos.x + \
		dir.x * PLAYER_MOVEMENT_LIMIT)][(int)(pos.y)])
		cube->player->pos.x += dir.x * PLAYER_SPEED;
	if (!cube->map->map[(int)(pos.x)][(int)(pos.y + \
		dir.y * PLAYER_MOVEMENT_LIMIT)])
		cube->player->pos.y += dir.y * PLAYER_SPEED;
}

void	movement_hook_vertical(t_cube *cube, t_bool	is_forward)
{
	t_vector2D	pos;
	t_vector2D	dir;

	pos.x = cube->player->pos.x;
	pos.y = cube->player->pos.y;
	dir.x = cube->player->dir.x;
	dir.y = cube->player->dir.y;
	if (is_forward)
		change_map_pos(pos, dir, cube);
	if (!is_forward)
	{
		if (!cube->map->map[(int)(pos.x - dir.x \
			* PLAYER_MOVEMENT_LIMIT)][(int)(pos.y)])
			cube->player->pos.x -= dir.x * PLAYER_SPEED;
		if (!cube->map->map[(int)(pos.x)][(int)(pos.y - dir.y \
			* PLAYER_MOVEMENT_LIMIT)])
			cube->player->pos.y -= dir.y * PLAYER_SPEED;
	}
	draw(cube);
}
