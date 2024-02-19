/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_t_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:10:39 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 16:12:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_color	int_to_t_color(int color)
{
	t_color	tmp;
	int		color_copy;

	color_copy = color;
	color_copy = color_copy << ENDIAN_CONVERSION;
	color_copy = color_copy >> 3 * ENDIAN_CONVERSION;
	tmp.g = color_copy;
	tmp.b = color_copy;
	color_copy = color;
	color_copy = color_copy >> ENDIAN_CONVERSION;
	color_copy = color_copy << 3 * ENDIAN_CONVERSION;
	color_copy = color_copy >> 3 * ENDIAN_CONVERSION;
	tmp.g = color_copy;
	color_copy = color;
	color_copy = color_copy << 3 * ENDIAN_CONVERSION;
	color_copy = color_copy >> 3 * ENDIAN_CONVERSION;
	tmp.r = color_copy;
	return (tmp);
}
