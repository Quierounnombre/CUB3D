/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:25 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 10:24:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_texture(t_texture *texture)
{
	texture->height = 0;
	texture->width = 0;
	texture->n_colors = 0;
	texture->color_per_pixel = 0;
	texture->color_dictionary = NULL;
	texture->raw = NULL;
	texture->file = "./textures/N.xpm";
}
