/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:48:44 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/09 12:09:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	check_north(char **dump, int lines, t_cube *cube)
{
	(void)cube;
	char	**split;
	int		found;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "NO", ft_strlen(split[0])) == 0)
		{
			found++;
			ft_printf("%s\n", split[1]);
			open_texture(split[1], cube, NORTH, &cube->map->north);
		}
		free_split(split);
	}
	if (found == 1)
		return (true);
	else
		return (false);
}

t_bool	check_south(char **dump, int lines, t_cube *cube)
{
	(void)cube;
	char	**split;
	int		found;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "SO", ft_strlen(split[0])) == 0)
		{
			found++;
			open_texture(split[1], cube, SOUTH, &cube->map->south);
		}
		free_split(split);
	}
	if (found == 1)
		return (true);
	else
		return (false);
}

t_bool	check_west(char **dump, int lines, t_cube *cube)
{
	(void)cube;
	char	**split;
	int		found;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "WE", ft_strlen(split[0])) == 0)
		{
			found++;
			open_texture(split[1], cube, WEST, &cube->map->west);
		}
		free_split(split);
	}
	if (found == 1)
		return (true);
	else
		return (false);
}

t_bool	check_east(char **dump, int lines, t_cube *cube)
{
	(void)cube;
	char	**split;
	int		found;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "EA", ft_strlen(split[0])) == 0)
		{
			found++;
			open_texture(split[1], cube, EAST, &cube->map->east);
		}
		free_split(split);
	}
	if (found == 1)
		return (true);
	else
		return (false);
}

t_bool	check_texture(char **dump, int lines, t_cube *cube)
{
	if (check_north(dump, lines, cube) == true
		&& check_south(dump, lines, cube) == true
		&& check_west(dump, lines, cube) == true
		&& check_east(dump, lines, cube) == true)
	{
		return (true);
	}
	else
		return (false);
}
