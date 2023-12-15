/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:54:19 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/15 16:58:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	fill_window(t_color color, t_vector2D start, t_vector2D end,
		t_cube *cube)
{
	t_vector2D	v;

	v.x = start.x;
	v.y = start.y;
	while (v.x < end.x)
	{
		while (v.y < end.y)
		{
			v.y++;
			mlx_point_draw(cube, v.x, v.y, color);
		}
		v.x++;
		v.y = start.y;
	}
}
