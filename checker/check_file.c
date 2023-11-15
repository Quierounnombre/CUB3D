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

int count_lines(t_path path, t_cube *cube)
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
		return 1;
	else
		return 0;
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
	i = -1;
	close (fd);
	return dump;
}

char	**check_file(t_cube *cube, t_path path)
{
	int		n_lines;
	char	**dump;
	char	**map;

	n_lines = count_lines(path, cube);
	dump = fill_dump(n_lines, path, cube);
	if (!check_texture(dump, n_lines, cube) || !check_color(dump, n_lines, cube)
		|| !check_map(dump))
	{
		free_split(dump);
		exit_error("Fallo Texturas, Color o Mapa", errno, cube);
	}
	map = get_map(dump, n_lines, cube);
	/*
	if (check_walls(map))
	{
		free_split(map);
		exit_error("Fallo Paredes", errno, cube);
	}
	*/
	free_split(dump);
	return (map);
}