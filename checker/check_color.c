/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:52:23 by alfgarci          #+#    #+#             */
/*   Updated: 2024/03/14 12:04:29 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	check_color_floor(char **dump, int lines, t_cube *cube)
{
	char	**split;
	char	**split_c;
	int		found;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "F", ft_strlen(split[0])) == 0)
		{
			found++;
			split_c = ft_split(split[1], ',');
			cube->map->floor.r = ft_wrap(ft_atoi(split_c[0]), 0, 256);
			cube->map->floor.g = ft_wrap(ft_atoi(split_c[1]), 0, 256);
			cube->map->floor.b = ft_wrap(ft_atoi(split_c[2]), 0, 256);
			free_split(split_c);
		}
		free_split(split);
	}
	if (found == 1)
		return (true);
	else
		return (false);
}

t_bool	check_color_ceiller(char **dump, int lines, t_cube *cube)
{
	char	**split;
	char	**split_c;
	int		found;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "C", ft_strlen(split[0])) == 0)
		{
			found++;
			split_c = ft_split(split[1], ',');
			cube->map->celing.r = ft_wrap(ft_atoi(split_c[0]), 0, 256);
			cube->map->celing.g = ft_wrap(ft_atoi(split_c[1]), 0, 256);
			cube->map->celing.b = ft_wrap(ft_atoi(split_c[2]), 0, 256);
			free_split(split_c);
		}
		free_split(split);
	}
	if (found == 1)
		return (true);
	else
		return (false);
}

t_bool	check_color(char **dump, int lines, t_cube *cube)
{
	if (check_color_floor(dump, lines, cube) == true
		&& check_color_ceiller(dump, lines, cube) == true)
	{
		return (true);
	}
	else
		return (false);
}
