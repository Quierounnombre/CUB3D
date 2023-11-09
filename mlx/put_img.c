/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:43:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 13:59:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	put_img(t_cube *cube, t_img img, int x, int y)
{
	if (mlx_put_image_to_window(cube->mlx, cube->win, img, x, y) <= 0)
		exit_error(ERROR_MLX_PUT_IMG, errno, cube);
}
