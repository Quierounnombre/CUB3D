/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:35:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:42:50 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_cube	*init(t_path file)
{
	t_cube	*local_cube;

	local_cube = NULL;
	local_cube = init_cube(local_cube, file);
	local_cube->map = init_map(local_cube);
	local_cube->cam = init_cam(local_cube);
	return (local_cube);
}
