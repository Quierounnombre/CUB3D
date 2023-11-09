/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:40:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/08 02:13:49 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	free_map(t_map	*map)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
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
		free(cube);
	}
}
