/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:24:22 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 18:07:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static char	*store_end_of_map(t_point **local_map, t_cube *cube)
{
	int		i;
	char	*s;

	i = 0;
	while ((*local_map)[i] != END_OF_MAP)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		exit_error(ERROR_MALLOC, errno, cube);
	i = 0;
	while ((*local_map)[i] != END_OF_MAP)
	{
		s[i] = END_OF_MAP;
		i++;
	}
	s[i] = '\0';
	return (s);
}

t_point	**store_map(char **raw_map, t_cube *cube)
{
	t_point	**local_map;
	char	*end_line;
	int		i;

	i = 0;
	local_map = NULL;
	while (raw_map[i])
	{
		local_map = increase_map_size(i, local_map, cube);
		local_map[i] = store_map_line(raw_map[i], cube);
		free(raw_map[i]);
		i++;
	}
	end_line = store_end_of_map(local_map, cube);
	local_map[i] = store_map_line(end_line, cube);
	free(end_line);
	free(raw_map);
	return (local_map);
}
