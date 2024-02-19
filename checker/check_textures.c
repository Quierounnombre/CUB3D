/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:48:44 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	check_north(char **dump, int lines, t_cube *cube)
{
	char	**split;
	int		found;
	char	*texture;
	int		i;

	found = 0;
	i = -1;
	while (++i < lines)
	{
		split = ft_split(dump[i], ' ');
		if (ft_strncmp(split[0], "NO", ft_strlen(split[0])) == 0)
		{
			found++;
			texture = ft_strtrim(split[1], "\n");
			open_texture(texture, cube, 'N', &cube->map->north);
			free(texture);
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
	char	*texture;
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
			texture = ft_strtrim(split[1], "\n");
			open_texture(texture, cube, 'S', &cube->map->south);
			free(texture);
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
	char	*texture;
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
			texture = ft_strtrim(split[1], "\n");
			open_texture(texture, cube, 'W', &cube->map->west);
			free(texture);
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
	char	*texture;
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
			texture = ft_strtrim(split[1], "\n");
			open_texture(texture, cube, 'E', &cube->map->east);
			free(texture);
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
