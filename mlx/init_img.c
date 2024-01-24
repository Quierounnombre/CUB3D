/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:26:37 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/15 16:59:27 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_img(t_cube *cube)
{
	cube->mlx_img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->mlx_img->img)
		exit_error(ERROR_MLX_IMG, errno, cube);
	cube->mlx_img->adres = mlx_get_data_addr(cube->mlx_img->img,
			&cube->mlx_img->bits_per_pixel,
			&cube->mlx_img->line,
			&cube->mlx_img->endian);
}
