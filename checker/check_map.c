/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:47:17 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/17 00:27:04 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	get_max_char(char **dump, int map_lines)
{
	int		i;
	size_t	max_char;

	i = map_lines;
	max_char = ft_strlen(dump[i]);
	while (dump[++map_lines])
		if (ft_strlen(dump[i]) > max_char)
			max_char = ft_strlen(dump[i]);
	return (max_char);
}

int	map_line(char **dump)
{
	int		i;
	int		count;
	char	**tmp;

	i = -1;
	count = 0;
	while (dump[++i])
	{
		tmp = ft_split(dump[i], ' ');
		if (dump[i][0] == '\n' || !ft_strncmp(tmp[0], "NO", 2)
			|| !ft_strncmp(tmp[0], "SO", 2) || !ft_strncmp(tmp[0], "WE", 2)
			|| !ft_strncmp(tmp[0], "EA", 2) || !ft_strncmp(tmp[0], "F", 2)
			|| !ft_strncmp(tmp[0], "C", 2))
		{
			count++;
		}
		free_split(tmp);
	}
	return (count);
}

char	**reserve_map(int map_lines, int max_char_in_map, t_cube *cube)
{
	char	**map;
	int		i;
	int		k;

	i = -1;
	map = (char **)malloc((map_lines + 1) * sizeof(char *));
	if (!map)
		exit_error(ERROR_MALLOC, errno, cube);
	while (++i < map_lines)
	{
		map[i] = (char *)malloc((max_char_in_map + 1) * sizeof(char));
		if (!map[i])
		{
			k = -1;
			while (++k < i)
				free(map[k]);
			free(map);
			exit_error(ERROR_MALLOC, errno, cube);
		}
	}
	return (map);
}

char	**get_map(char **dump, int n_lines, t_cube *cube)
{
	int		map_lines;
	int		start_map;
	size_t	max_char_in_map;
	int		i;
	size_t	j;
	char	**map;

	start_map = map_line(dump);
	map_lines = n_lines - map_line(dump);
	max_char_in_map = get_max_char(dump, start_map);
	map = reserve_map(map_lines, max_char_in_map, cube);
	i = 0;
	while (dump[start_map])
	{
		j = 0;
		while (j < ft_strlen(dump[start_map]))
		{
			if (dump[start_map][j] == ' ')
				map[i][j] = 'v';
			else if (dump[start_map][j] == '\n')
				break ;
			else
				map[i][j] = dump[start_map][j];
			j++;
		}
		while (j < max_char_in_map)
		{
			map[i][j] = 'v';
			j++;
		}
		map[i][j - 1] = '\0';
		i++;
		start_map++;
	}
	map[i] = NULL;
	return (map);
}

t_bool	check_map(char **dump)
{
	int		start_map;
	int		j;
	char	tmp;

	start_map = map_line(dump);
	while (dump[start_map])
	{
		j = 0;
		while (dump[start_map][j])
		{
			tmp = dump[start_map][j];
			if (tmp != '0' && tmp != '1' && tmp != ' ' && tmp != 'N'
				&& tmp != 'S' && tmp != 'E' && tmp != 'W' && tmp != '\n')
			{
				return (false);
			}
			j++;
		}
		start_map++;
	}
	return (true);
}
