/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:08:03 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/09 12:22:27 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_map	*init_map(t_cube *cube)
{
	t_map	*local_map;

	local_map = (t_map *)malloc(sizeof(t_map));
	if (!local_map)
		exit_error(ERROR_MALLOC, errno, cube);
	init_texture(&local_map->north, cube);
	init_texture(&local_map->south, cube);
	init_texture(&local_map->west, cube);
	init_texture(&local_map->east, cube);
	return (local_map);
}
