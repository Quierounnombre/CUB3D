/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:49:18 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/21 14:32:38 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static int	movement_hooks(t_key keycode, void *param)
{
	t_cube	*cube;

	cube = param;
	if (keycode == KEY_FORWARD)
		movement_hook_vertical(cube, true);
	if (keycode == KEY_BACKWARD)
		movement_hook_vertical(cube, false);
	if (keycode == KEY_ROTATE_RIGHT)
		rotate_hook(cube, true);
	if (keycode == KEY_ROTATE_LEFT)
		rotate_hook(cube, false);
	if (keycode == KEY_MOVE_RIGHT)
		movement_hook_horizontal(cube, true);
	if (keycode == KEY_MOVE_LEFT)
		movement_hook_horizontal(cube, false);
	if (keycode == KEY_ESCAPE)
		close_hook(cube);
	return (0);
}

void	setup_hooks(t_cube *cube)
{
	mlx_hook(cube->win, 2, 0, movement_hooks, cube);
	mlx_do_key_autorepeaton(cube->mlx);
	mlx_hook(cube->win, 17, 0, close_hook, cube);
}
