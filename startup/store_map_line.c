/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:27:16 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 18:07:38 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static t_point	convert_to_t_point(char c)
{
	t_point	local_point;

	local_point = (c - '0');
	return (local_point);
}

t_point	*store_map_line(char *s, t_cube *cube)
{
	t_point	*line;
	int		i;

	i = ft_strlen(s);
	line = (t_point *)malloc(sizeof(t_point) * (i + 1));
	if (!line)
		exit_error(ERROR_MALLOC, errno, cube);
	i = 0;
	while (s[i])
	{
		line[i] = convert_to_t_point(s[i]);
		i++;
	}
	line[i] = END_OF_MAP;
	return (line);
}
