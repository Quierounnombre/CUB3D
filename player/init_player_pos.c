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

static void	calc_plane_vecor(t_cube *cube)
{
	double	plane_len;

	plane_len = tan((PLAYER_FOV * M_PI / 180) / 2);
	cube->player->plane.x = cube->player->dir.y * plane_len;
	cube->player->plane.y = (-1) * (cube->player->dir.x) * plane_len;
}

static void	set_coor_player(t_cube *cube, int i, int j, double angle)
{
	cube->player->pos.x = j;
	cube->player->pos.y = i;
	cube->player->angle = angle;
	cube->player->dir.x = cos(angle);
	cube->player->dir.y = sin(angle);
	calc_plane_vecor(cube);
}

void	init_player_pos(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				set_coor_player(cube, i, j, (M_PI / 2));
			else if (map[i][j] == 'N')
				set_coor_player(cube, i, j, M_PI);
			else if (map[i][j] == 'W')
				set_coor_player(cube, i, j, ((3.0 / 2.0) * M_PI));
			else if (map[i][j] == 'S')
				set_coor_player(cube, i, j, 0);
		}
	}
}
