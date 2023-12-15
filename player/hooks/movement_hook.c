/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 14:50:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	movement_hook(t_cube *cube, t_bool	is_forward)
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	pos_x = cube->player->pos.x;
	pos_y = cube->player->pos.y;
	dir_x = cube->player->dir.x;
	dir_y = cube->player->dir.y;
	if (is_forward)
	{
		if (!cube->map->map[(int)(pos_x + dir_x * PLAYER_SPEED)][(int)(pos_y)])
			cube->player->pos.x += dir_x * PLAYER_SPEED;
		if (!cube->map->map[(int)(pos_x)][(int)(pos_y + dir_y * PLAYER_SPEED)])
			cube->player->pos.y += dir_y * PLAYER_SPEED;
	}
	if (!is_forward)
	{
		if (!cube->map->map[(int)(pos_x - dir_x * PLAYER_SPEED)][(int)(pos_y)])
			cube->player->pos.x -= dir_x * PLAYER_SPEED;
		if (!cube->map->map[(int)(pos_x)][(int)(pos_y - dir_y * PLAYER_SPEED)])
			cube->player->pos.y -= dir_y * PLAYER_SPEED;
	}
	draw(cube);
}
