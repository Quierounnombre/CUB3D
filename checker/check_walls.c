/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:47:36 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/09 12:47:40 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static t_bool	check_north_wall(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;

	i = -1;
	j = -1;
	res = false;
	while (++j < colums - 1)
	{
		i = -1;
		while (++i < rows - 1)
			if (map[i][j] == '1')
				res = true;
	}
	return (res);
}

static t_bool	check_west_wall(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;

	i = -1;
	res = false;
	while (++i < rows - 1)
	{
		j = -1;
		while (++j < colums - 1)
			if (map[i][j] == '1')
				res = true;
	}
	return (res);
}

static t_bool	check_east_wall(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;

	i = rows - 1;
	j = colums - 1;
	res = false;
	while (i > 0)
	{
		j = rows - 1;
		while (j > 0)
		{
			if (map[i][j] == '1')
				res = true;
			j--;
		}
		i--;
	}
	return (res);
}

static t_bool	check_south_wall(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;

	i = colums - 1;
	j = rows - 1;
	res = false;
	while (j > 0)
	{
		i = rows - 1;
		while (i > 0)
		{
			if (map[i][j] == '1')
				res = true;
			i--;
		}
		j--;
	}
	return (res);
}

t_bool	check_walls(char **map)
{
	int	rows;
	int	cols;

	matrix_dimension(map, &rows, &cols);
	if (check_north_wall(map, rows, cols) == true
		&& check_west_wall(map, rows, cols) == true
		&& check_south_wall(map, rows, cols) == true
		&& check_east_wall(map, rows, cols) == true)
	{
		return true;
	}
	else
	{
		return true;
	}
}
