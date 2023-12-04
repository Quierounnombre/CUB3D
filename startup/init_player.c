/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:18:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 14:48:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_player	*init_player(t_cube *cube)
{
	t_player	*local_player;

	local_player = (t_player *)malloc(sizeof(t_player));
	if (!local_player)
		exit_error(ERROR_MALLOC, errno, cube);
	local_player->angle = PLAYER_DEFAULT_ANGLE;
	local_player->fov = PLAYER_FOV;
	local_player->pos = load_vector2d(PLAYER_DEFAULT_POS_X,
			PLAYER_DEFAULT_POS_Y);
	return (local_player);
}
