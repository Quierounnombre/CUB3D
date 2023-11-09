/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:40:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 13:32:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	free_map(t_map	*map)
{
	int		i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
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
		if (cube->cam)
			free(cube->cam);
		if (cube->map)
			free_map(cube->map);
		if (cube->mlx_img)
			free(cube->mlx_img);
		free(cube);
	}
}
