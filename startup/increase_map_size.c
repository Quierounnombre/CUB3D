/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_map_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:42:54 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 17:54:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_point	**increase_map_size(int size, t_point **map, t_cube *cube)
{
	t_point	**local_map;
	int		i;

	i = 0;
	local_map = (t_point **)malloc(sizeof(t_point *) * (size + 1));
	if (!local_map)
		exit_error(ERROR_MALLOC, errno, cube);
	if (!map)
		return (local_map);
	while (map[i])
	{
		local_map[i] = map[i];
		i++;
	}
	free(map);
	return (local_map);
}
