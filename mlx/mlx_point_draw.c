/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_point_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:21 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/15 17:31:54 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static int	endian_conversion(t_color color)
{
	return ((color.b)
		+ (color.g << ENDIAN_CONVERSION)
		+ (color.r << (2 * ENDIAN_CONVERSION)));
}

void	mlx_point_draw(t_cube *cube, int x, int y, t_color input_color)
{
	unsigned int	color;

	color = endian_conversion(input_color);
	if ((x < HEIGHT - 1 && x > -1) && (y < WIDTH - 1 && y > -1))
		ft_pixel_put(cube->mlx_img, x, y, color);
}
