/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/15 17:38:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw(t_cube *cube)
{
	draw_background(cube);
	raycasting(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->mlx_img->img, 0, 0);
}
