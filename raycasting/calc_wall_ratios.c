/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_ratios.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:27:31 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 17:24:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

//Asume that pos.y is already calculated by the raycasting

t_vector2D	calc_wall_ratios(t_texture *texture, t_vector2D pos)
{
	t_vector2D	ratios;

	//pos.x es la columna
	ratios.x = pos.x / texture->height;
	ratios.y = pos.y;
	return (ratios);
}
