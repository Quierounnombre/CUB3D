/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:25 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/09 11:43:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_texture(t_texture *texture, t_cube *cube)
{
	texture->height = 0;
	texture->width = 0;
	texture->img = init_mlx_img(cube);
}
