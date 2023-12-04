/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw(t_cube *cube)
{
	t_vector2D	v1;
	t_vector2D	v2;
	int			i;

	i = 0;
	v1 = load_vector2d(0, 0);
	v2 = load_vector2d(HEIGHT, WIDTH / 2);
	fill_window(cube->map->texture.celing, v1, v2, cube);
	v2.x = 0;
	v1 = load_vector2d(HEIGHT, WIDTH);
	fill_window(cube->map->texture.floor, v2, v1, cube);
	i = 200;
	while (i < 800)
	{
		draw_wall(400, i, cube);
		i++;
	}
}
