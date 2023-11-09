/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_open_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:59:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 13:10:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	mlx_open_win(t_cube *cube)
{
	cube->win = mlx_new_window(cube->mlx, HEIGHT, WIDTH, NAME);
	if (!cube->mlx)
		exit_error(ERROR_MLX_WIN, errno, cube);
}
