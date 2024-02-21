/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hook_horizontal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:42 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/21 14:44:52 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	movement_hook_horizontal(t_cube *cube, t_bool is_right)
{
	t_vector2D	pos;
	t_vector2D	dir;

	pos.x = cube->player->pos.x;
	pos.y = cube->player->pos.y;
	dir.x = cube->player->dir.x;
	dir.y = cube->player->dir.y;
	if (is_right)
	{
		if (!cube->map->map[(int)(pos.x + dir.x * PLAYER_SPEED)][(int)(pos.y)])
			cube->player->pos.y += dir.x * PLAYER_SPEED;
		if (!cube->map->map[(int)(pos.x)][(int)(pos.y + dir.y * PLAYER_SPEED)])
			cube->player->pos.x += dir.y * PLAYER_SPEED;
	}
	if (!is_right)
	{
		if (!cube->map->map[(int)(pos.x - dir.x * PLAYER_SPEED)][(int)(pos.y)])
			cube->player->pos.y -= dir.x * PLAYER_SPEED;
		if (!cube->map->map[(int)(pos.x)][(int)(pos.y - dir.y * PLAYER_SPEED)])
			cube->player->pos.x -= dir.y * PLAYER_SPEED;
	}
	draw(cube);
}
