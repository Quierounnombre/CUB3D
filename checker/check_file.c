/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:43:30 by alfgarci          #+#    #+#             */
/*   Updated: 2024/03/07 19:33:09 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	dimensions_map(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	cube->map->height = i;
	cube->map->width = j;
}

int	count_lines(t_path path, t_cube *cube)
{
	t_fd	fd;
	int		count;
	char	*line;

	count = 0;
	fd = open_fd(path, cube);
	line = ft_get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

int	is_empty_line(char *line)
{
	if (ft_split(line, ' ') == NULL)
		return (1);
	else
		return (0);
}

char	**fill_dump(int n_lines, t_path path, t_cube *cube)
{
	char	*line;
	char	**dump;
	t_fd	fd;
	int		i;

	fd = open_fd(path, cube);
	dump = (char **)malloc((n_lines + 1) * sizeof(char *));
	line = ft_get_next_line(fd);
	i = -1;
	while (line)
	{
		dump[++i] = line;
		line = ft_get_next_line(fd);
	}
	dump[++i] = NULL;
	close (fd);
	return (dump);
}

void	check_fill_file(t_cube *cube, t_path path)
{
	int		n_lines;
	char	**dump;
	char	**map;

	n_lines = count_lines(path, cube);
	dump = fill_dump(n_lines, path, cube);
	if (!check_texture(dump, n_lines, cube) || !check_color(dump, n_lines, cube)
		|| !check_map(dump) || !check_pos(dump))
	{
		free_split(dump);
		exit_error(ERROR_FORMAT, errno, cube);
	}
	map = get_map(dump, n_lines, get_max_len_line(dump, map_line(dump)), cube);
	free_split(dump);
	if (is_map_closed(map) == false)
	{
		free_split(map);
		exit_error(ERROR_WALLS, errno, cube);
	}
	dimensions_map(cube, map);
	init_player_pos(cube, map);
	cube->map->map = to_int_ar(map, cube->map->height, cube->map->width, cube);
	free_split(map);
}
