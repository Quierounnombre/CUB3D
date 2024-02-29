/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:43:30 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/29 15:05:24 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	check_pos(char **dump)
{
	int		start_map;
	int		j;
	int		pos;
	char	tmp;

	pos = 0;
	start_map = map_line(dump);
	while (dump[start_map])
	{
		j = 0;
		while (dump[start_map][j])
		{
			tmp = dump[start_map][j];
			if (tmp == 'S' || tmp == 'E' || tmp == 'W' || tmp == 'N')
				pos++;
			j++;
		}
		start_map++;
	}
	if (pos == 1)
		return (true);
	else
		return (false);
}
