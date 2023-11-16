/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:48:44 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/17 00:21:46 by alfgarci         ###   ########.fr       */
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
			//cube->map->texture->north = open_texture(split[1]);
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
			//cube->map->texture->south = open_texture(split[1]);
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
			//cube->map->texture->west = open_texture(split[1]);
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
			//cube->map->texture->east = open_texture(split[1]);
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
