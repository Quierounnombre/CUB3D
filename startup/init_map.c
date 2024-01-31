/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:08:03 by vicgarci          #+#    #+#             */
/*   Updated: 2024/01/24 15:52:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_map	*init_map(t_cube *cube)
{
	t_map	*local_map;

	local_map = (t_map *)malloc(sizeof(t_map));
	if (!local_map)
		exit_error(ERROR_MALLOC, errno, cube);
	init_texture(&local_map->north);
	init_texture(&local_map->south);
	init_texture(&local_map->west);
	init_texture(&local_map->east);
	return (local_map);
}
