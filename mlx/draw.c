/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:35 by vicgarci          #+#    #+#             */
/*   Updated: 2024/01/24 15:18:54 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw(t_cube *cube)
{
	draw_background(cube);
	raycasting(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->mlx_img->img, 0, 0);
}
