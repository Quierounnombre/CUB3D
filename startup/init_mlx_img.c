/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 13:32:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_mlx_img	*init_mlx_img(t_cube *cube)
{
	t_mlx_img	*local_img;

	local_img = (t_mlx_img *)malloc(sizeof(t_mlx_img));
	if (!local_img)
		exit_error(ERROR_MALLOC, errno, cube);
	return (local_img);
}
