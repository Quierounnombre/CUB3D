/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:40:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:49:46 by vicgarci         ###   ########.fr       */
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
