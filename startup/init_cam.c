/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:18:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 14:48:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_cam	*init_cam(t_cube *cube)
{
	t_cam	*local_cam;

	local_cam = (t_cam *)malloc(sizeof(t_cam));
	if (!local_cam)
		exit_error(ERROR_MALLOC, errno, cube);
	return (local_cam);
}