/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:25 by vicgarci          #+#    #+#             */
/*   Updated: 2024/01/31 19:52:00 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_texture(t_texture *texture)
{
	texture->height = 0;
	texture->width = 0;
	texture->raw = NULL;
	texture->file = "./textures/N.xpm";
}
