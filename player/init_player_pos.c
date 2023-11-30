/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:04:40 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/30 15:04:42 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_player_pos(t_cube *cube)
{
	while (cube->map->map[++i])
	{
		while (cube->map->map[i][++j])
		{
			if (cube->map->map[i][++j] == 'N')
				cube->plyer->angle = 0;
			else if (cube->map->map[i][++j] == 'O')
				cube->plyer->angle = (PI/2);
			else if (cube->map->map[i][++j] == 'S')
				cube->plyer->angle = (PI);
			else if (cube->map->map[i][++j] == 'E')
				cube->plyer->angle = (3/2) * PI;
			//meto la pos
		}
	}
}