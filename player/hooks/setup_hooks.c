/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:49:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:40:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static int	movement_hooks(t_key keycode, void *param)
{
	t_cube	*cube;

	cube = param;
	if (keycode == KEY_FORWARD)
		movement_hook(cube, true);
	if (keycode == KEY_BACKWARD)
		movement_hook(cube, false);
	if (keycode == KEY_ROTATE_RIGHT)
		rotate_hook(cube, true);
	if (keycode == KEY_ROTATE_LEFT)
		rotate_hook(cube, false);
	if (keycode == KEY_ESCAPE)
		close_hook(cube);
	return (0);
}

void	setup_hooks(t_cube *cube)
{
	mlx_key_hook(cube->win, movement_hooks, cube);
	mlx_hook(cube->win, 17, 0, close_hook, cube);
}
