/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:04:40 by alfgarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:12:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_player_pos(t_cube *cube)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cube->map->map[++i])
	{
		while (cube->map->map[i][++j])
		{
			if (cube->map->map[i][++j] == 'N')
				cube->player->angle = 0;
			else if (cube->map->map[i][++j] == 'O')
				cube->player->angle = (M_PI / 2);
			else if (cube->map->map[i][++j] == 'S')
				cube->player->angle = (M_PI);
			else if (cube->map->map[i][++j] == 'E')
				cube->player->angle = (3 / 2) * M_PI;
			//meto la pos
		}
	}
}