/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 15:53:05 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw(t_cube *cube)
{
	int		i;
	int		j;
	t_color	color;

	i = 0;
	j = 0;
	color.b = 0;
	color.g = 128;
	color.r = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			mlx_point_draw(cube, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
}
