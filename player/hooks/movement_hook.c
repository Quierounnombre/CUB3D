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
	int		dir;

	dir = 1;
	if (!is_forward)
		dir = -1;
	cube->player->pos.x += \
	sin(cube->player->angle) * PLAYER_SPEED * dir;
	cube->player->pos.y += \
	cos(cube->player->angle) * PLAYER_SPEED * dir;
	draw(cube);
}
