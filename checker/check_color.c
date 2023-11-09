/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:52:23 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/08 02:13:49 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	check_color_floor(char **dump, int lines, t_cube *cube)
{
	char	**split;
	char	**split_color;
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
			split_color = ft_split(split[1], ',');
			cube->map->texture.floor.r = ft_wrap(ft_atoi(split_color[0]), 0, 255);
			cube->map->texture.floor.g = ft_wrap(ft_atoi(split_color[1]), 0, 255);
			cube->map->texture.floor.b = ft_wrap(ft_atoi(split_color[2]), 0, 255);
			free_split(split_color);
		}
		free_split(split);
	}
	if (found == 1)
		return true;
	else
		return false;
}

t_bool	check_color_ceiller(char **dump, int lines, t_cube *cube)
{
	char	**split;
	char	**split_color;
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
			split_color = ft_split(split[1], ',');
			cube->map->texture.floor.r = ft_wrap(ft_atoi(split_color[0]), 0, 255);
			cube->map->texture.floor.g = ft_wrap(ft_atoi(split_color[1]), 0, 255);
			cube->map->texture.floor.b = ft_wrap(ft_atoi(split_color[2]), 0, 255);
			free_split(split_color);
		}
		free_split(split);
	}
	if (found == 1)
		return true;
	else
		return false;
}

t_bool	check_color(char **dump, int lines, t_cube *cube)
{
	if (check_color_floor(dump, lines, cube) == true
		&& check_color_ceiller(dump, lines, cube) == true)
	{
		return true;
	}
	else
		return true;
}