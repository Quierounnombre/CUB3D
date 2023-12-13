/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:48:03 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/09 12:48:13 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	free_split(char **split)
{
	int	aux;

	aux = -1;
	while (*(split + ++aux))
		free(*(split + aux));
	free(split);
}

void	matrix_dimension(char **arr, int *rows, int *cols)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	*rows = i;
	*cols = ft_strlen(arr[0]);
}

static int	**reserve_int_arr(int rows, int cols)
{
	int	**output;
	int	i;
	int	k;

	i = -1;
	output = (int **)malloc(rows * sizeof(int *));
	if (output == NULL)
		return (NULL);
	while (++i < rows)
	{
		output[i] = (int *)malloc(cols * sizeof(int));
		if (output[i] == NULL)
		{
			k = -1;
			while (++k < i)
				free(output[k]);
			free(output);
			return (NULL);
		}
	}
	return (output);
}

int	**to_int_ar(char **map, int rows, int cols, t_cube *cube)
{
	int	**output;
	int	i;
	int	j;

	i = -1;
	output = reserve_int_arr(rows, cols);
	if (output == NULL)
		exit_error(ERROR_MALLOC, errno, cube);
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (map[i][j] == '1')
				output[i][j] = 1;
			else
				output[i][j] = 0;
		}
	}
	return (output);
}
