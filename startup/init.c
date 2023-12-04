/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:35:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 13:39:01 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_cube	*init(t_path file)
{
	t_cube	*local_cube;

	local_cube = NULL;
	local_cube = init_cube(local_cube, file);
	local_cube->map = init_map(local_cube);
	set_default_colors(local_cube->map);
	local_cube->player = init_player(local_cube);
	local_cube->mlx_img = init_mlx_img(local_cube);
	mlx_start(local_cube);
	init_img(local_cube);
	mlx_open_win(local_cube);
	put_img(local_cube, local_cube->mlx_img->img, 0, 0);
	mlx_key_hook(local_cube->win, setup_hooks, local_cube);
	return (local_cube);
}
