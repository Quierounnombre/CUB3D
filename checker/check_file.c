/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:43:30 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/09 00:42:46 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int count_lines(t_path *path)
{
	t_fd	fd;
	int		count;
	char	*line;

	count = 0;
	fd = open_fd(path);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (count);
}

int	is_empty_line(char *line)
{
	if (ft_split(line, ' ') == NULL)
		return 1;
	else
		return 0;
}

char	**fill_dump(int n_lines, t_path *path)
{
	char	*line;
	char	**dump;
	t_fd	fd;
	int		i;

	fd = open_fd(path);
	dump = (char **)malloc(n_lines * sizeof(char *));
	line = get_next_line(fd);
	i = -1;
	while (line)
		dump[++i] = line;
	return dump;
}

char	**check_file(t_cube *cube, t_path *path)
{
	char	*line;
	int		n_lines;
	char	**dump;
	char	**map;

	n_lines = count_lines(path);
	dump = fill_dump(n_lines, path);
	if (!check_texture(dump, n_lines, cube) || !check_color(dump, n_lines, cube)
		|| !check_map(dump, n_lines, cube))
	{
		free_split(dump);
		exit_error(ERROR_PARSE, 2, cube);
	}
	else
	{
		map = get_map(dump, n_lines);
		free_split(dump);
	}
	return (map);
}