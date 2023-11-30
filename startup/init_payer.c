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
	return (local_player);
}