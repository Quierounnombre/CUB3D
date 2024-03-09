/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:35:38 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/09 12:28:46 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_cube	*init(t_path file)
{
	t_cube	*local_cube;

	local_cube = NULL;
	local_cube = init_cube(local_cube, file);
	local_cube->map = init_map(local_cube);
	local_cube->player = init_player(local_cube);
	set_default_colors(local_cube->map);
	local_cube->mlx_img = init_mlx_img(local_cube);
	mlx_start(local_cube);
	init_img(local_cube);
	mlx_open_win(local_cube);
	put_img(local_cube, local_cube->mlx_img->img, 0, 0);
	setup_hooks(local_cube);
	return (local_cube);
}
