/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_open_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:59:49 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	mlx_open_win(t_cube *cube)
{
	cube->win = mlx_new_window(cube->mlx, HEIGHT, WIDTH, NAME);
	if (!cube->win)
		exit_error(ERROR_MLX_WIN, errno, cube);
}
