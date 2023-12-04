/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:04:40 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/30 17:03:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	set_coor_player(t_cube *cube, int i, int j, double angle)
{
	cube->player->pos.x = j;
	cube->player->pos.y = i;
	cube->player->angle = angle;
}

void	init_player_pos(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cube->map->map[++i])
	{
		j = -1;
		while (cube->map->map[i][++j])
		{
			if (cube->map->map[i][j] == 'N')
				set_coor_player(cube, i, j, 0);
			else if (cube->map->map[i][j] == 'E')
				set_coor_player(cube, i, j, (M_PI / 2));
			else if (cube->map->map[i][j] == 'S')
				set_coor_player(cube, i, j, M_PI);
			else if (cube->map->map[i][j] == 'W')
				set_coor_player(cube, i, j, ((3.0 / 2.0) * M_PI));
		}
	}
}