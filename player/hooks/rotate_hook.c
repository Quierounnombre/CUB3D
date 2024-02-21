/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:51:42 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/21 14:44:42 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static void	rotate_hook_right(t_cube *cube, t_vector2D dir, t_vector2D plane)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = dir.x;
	old_plane_x = plane.x;
	cube->player->dir.x = dir.x * cos(-PLAYER_ROTATE_SPEED)
		- dir.y * sin(-PLAYER_ROTATE_SPEED);
	cube->player->dir.y = old_dir_x * sin(-PLAYER_ROTATE_SPEED)
		+ dir.y * cos(-PLAYER_ROTATE_SPEED);
	cube->player->plane.x = plane.x * cos(-PLAYER_ROTATE_SPEED)
		- plane.y * sin(-PLAYER_ROTATE_SPEED);
	cube->player->plane.y = old_plane_x * sin(-PLAYER_ROTATE_SPEED)
		+ plane.y * cos(-PLAYER_ROTATE_SPEED);
}

static void	rotate_hook_left(t_cube *cube, t_vector2D dir, t_vector2D plane)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = dir.x;
	old_plane_x = plane.x;
	cube->player->dir.x = dir.x * cos(PLAYER_ROTATE_SPEED)
		- dir.y * sin(PLAYER_ROTATE_SPEED);
	cube->player->dir.y = old_dir_x * sin(PLAYER_ROTATE_SPEED)
		+ dir.y * cos(PLAYER_ROTATE_SPEED);
	cube->player->plane.x = plane.x * cos(PLAYER_ROTATE_SPEED)
		- plane.y * sin(PLAYER_ROTATE_SPEED);
	cube->player->plane.y = old_plane_x * sin(PLAYER_ROTATE_SPEED)
		+ plane.y * cos(PLAYER_ROTATE_SPEED);
}

void	rotate_hook(t_cube *cube, t_bool is_right)
{
	t_vector2D	dir;
	t_vector2D	plane;

	dir.x = cube->player->dir.x;
	dir.y = cube->player->dir.y;
	plane.x = cube->player->plane.x;
	plane.y = cube->player->plane.y;
	if (is_right)
		rotate_hook_right(cube, dir, plane);
	if (!is_right)
		rotate_hook_left(cube, dir, plane);
	draw(cube);
}
