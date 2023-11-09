/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:47:17 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/09 12:47:21 by alfgarci         ###   ########.fr       */
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

	i = -1;
	map = (char **)malloc( (map_lines + 1)* sizeof(char *));
	if (!map)
		exit_error(ERROR_MALLOC, errno, cube);
	while (++i < map_lines)
	{
		map[i] = (char *)malloc((max_char_in_map) * sizeof(char));
		if (!map[i])
		{
			//free rest
			exit_error(ERROR_MALLOC, errno, cube);
		}
	}

	return(map);
}

char	**get_map(char **dump, int n_lines, t_cube *cube)
{
	int		map_lines;
	size_t	max_char_in_map;
	int		i;
	size_t	j;
	char	**map;

	map_lines = n_lines - map_line(dump);
	max_char_in_map = get_max_char(dump, map_lines);
	map = reserve_map(map_lines, max_char_in_map, cube);
	i = 0;
	while (dump[map_lines - 1])
	{
		j = 0;
		while (j < ft_strlen(dump[map_lines -1]))
		{
			if (dump[map_lines -1][j] == ' ')
				map[i][j] = 'v';
			else
				map[i][j] = dump[map_lines-1][j];
			j++;
		}
		while (j < max_char_in_map)
		{
			map[i][j] = 'v';
			j++;
		}
		map[i][j-1] = '\0';
		i++;
		map_lines++;
	}
	map[i] = NULL;
	return map;
}
/*
char **get_map(char **dump, int n_lines)
{
	size_t	max_char_in_map;
	char	**map;
	int		map_lines;
	int		i;
	size_t	j;

	map_lines = map_line(dump);
	i = map_lines;
	max_char_in_map = get_max_char(dump, map_lines);
	
	map = (char **)malloc((n_lines - map_lines + 1) * sizeof(char *));
	while (++i < n_lines)
		map[i] = (char *)malloc((max_char_in_map + 1) * sizeof(char));

	map = (char **)malloc((max_char_in_map + 1) * sizeof(char *));
	while (i < n_lines)
	{
		map[i] = (char *)malloc((n_lines - map_lines + 1) * sizeof(char));
		i++;
	}

	i = map_lines;
	while (i < ft_strlen(dump[i]) - 1)
	{
		j = 0;
		while (j < n_lines)
		{
			if (dump[i][j] == ' ')
				map[i][j] = 'v';
			else
				map[i][j] = dump[i][j];
			ft_printf("%c", map[i][j]);
			j++;
		}
		while (j < max_char_in_map)
		{
			map[i][j] = 'v';
			j++;
		}
		map[i][j] = '\0';
		i++;
		ft_printf("\n");
	}
	ft_printf("fallo2\n");
	map[i] = NULL;
	return (map);
}
*/
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
			if ( tmp != '0' && tmp != '1' && tmp != ' ' && tmp != 'N'
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

