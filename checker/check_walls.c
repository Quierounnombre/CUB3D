/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:47:36 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/17 00:15:21 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static t_bool	check_east(char **map, int i, int j)
{
	int		rows;
	int		cols;

	matrix_dimension(map, &rows, &cols);
	while (j < cols)
	{
		if (map[i][j] == '1')
			return (true);
		j++;
	}
	return (false);
}

static t_bool	check_south(char **map, int i, int j)
{
	int		rows;
	int		cols;

	matrix_dimension(map, &rows, &cols);
	while (i < rows)
	{
		if (map[i][j] == '1')
			return (true);
		i++;
	}
	return (false);
}

static t_bool	check_north(char **map, int i, int j)
{
	int		rows;
	int		cols;

	matrix_dimension(map, &rows, &cols);
	while (i >= 0)
	{
		if (map[i][j] == '1')
			return (true);
		i--;
	}
	return (false);
}

static t_bool	check_west(char **map, int i, int j)
{
	int		rows;
	int		cols;

	matrix_dimension(map, &rows, &cols);
	while (j >= 0)
	{
		if (map[i][j] == '1')
			return (true);
		j--;
	}
	return (false);
}

t_bool	is_map_closed(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if (check_north(map, i, j) == false
					|| check_south(map, i, j) == false
					|| check_west(map, i, j) == false
					|| check_east(map, i, j) == false)
				{
					return (false);
				}
			}
		}
	}
	return (true);
}
