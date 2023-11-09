/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:09:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 13:10:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	mlx_start(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		exit_error(ERROR_MLX_INIT, errno, cube);
}
