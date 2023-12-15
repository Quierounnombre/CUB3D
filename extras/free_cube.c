/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:40:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 13:44:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	free_map(t_map	*map)
{
	int		i;

	i = 0;
	if (map->map)
	{
		while (i < map->height)
		{
			free(map->map[i]);
			i++;
		}
	}
	free(map->map);
	free(map);
}

void	free_cube(t_cube	*cube)
{
	if (cube)
	{
		if (cube->file)
			free(cube->file);
		if (cube->player)
			free(cube->player);
		if (cube->map)
			free_map(cube->map);
		if (cube->mlx_img)
			free(cube->mlx_img);
		free(cube);
	}
}
