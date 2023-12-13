/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:51:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:14:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	rotate_hook(t_cube *cube, t_bool is_right)
{
	double	dirX = cube->player->dir.x;
	double	dirY = cube->player->dir.y;
	double	planeX = cube->player->plane.x;
	double	planeY = cube->player->plane.y;

	if (is_right)
	{
		double oldDirX = dirX;
		cube->player->dir.x = dirX * cos(-PLAYER_ROTATE_SPEED) - dirY * sin(-PLAYER_ROTATE_SPEED);
		cube->player->dir.y = oldDirX * sin(-PLAYER_ROTATE_SPEED) + dirY * cos(-PLAYER_ROTATE_SPEED);
		double oldPlaneX = planeX;
		cube->player->plane.x = planeX * cos(-PLAYER_ROTATE_SPEED) - planeY * sin(-PLAYER_ROTATE_SPEED);
		cube->player->plane.y = oldPlaneX * sin(-PLAYER_ROTATE_SPEED) + planeY * cos(-PLAYER_ROTATE_SPEED);
	}
	if (!is_right)
	{
		double oldDirX = dirX;
		cube->player->dir.x = dirX * cos(PLAYER_ROTATE_SPEED) - dirY * sin(PLAYER_ROTATE_SPEED);
		cube->player->dir.y = oldDirX * sin(PLAYER_ROTATE_SPEED) + dirY * cos(PLAYER_ROTATE_SPEED);
		double oldPlaneX = planeX;
		cube->player->plane.x = planeX * cos(PLAYER_ROTATE_SPEED) - planeY * sin(PLAYER_ROTATE_SPEED);
		cube->player->plane.y = oldPlaneX * sin(PLAYER_ROTATE_SPEED) + planeY * cos(PLAYER_ROTATE_SPEED);
	}
	draw(cube);
}
