/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hook_horizontal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:42 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/21 15:11:25 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	movement_hook_horizontal(t_cube *cube, t_bool is_right)
{
	t_vector2D	pos;
	t_vector2D	dir;
	t_vector2D	delta;

	pos.x = cube->player->pos.x;
	pos.y = cube->player->pos.y;
	dir.x = cube->player->dir.x;
	dir.y = cube->player->dir.y;
	delta.x = dir.y * PLAYER_SPEED;
	delta.y = -dir.x * PLAYER_SPEED;
	if (is_right && !cube->map->map[(int)(pos.x + delta.x)][(int)(pos.y)])
	{
		cube->player->pos.x += delta.x;
		cube->player->pos.y += delta.y;
	}
	else
	{
		if (!cube->map->map[(int)(pos.x - delta.x)][(int)(pos.y)])
		{
			cube->player->pos.x -= delta.x;
			cube->player->pos.y -= delta.y;
		}
	}
	draw(cube);
}
