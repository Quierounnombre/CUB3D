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

void	matrix_dimension(char **arr,int *rows,int *cols)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	*rows = i;
	*cols = ft_strlen(arr[0]);
}