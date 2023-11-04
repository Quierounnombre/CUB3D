/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:08:03 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 14:49:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_map	*init_map(t_cube *cube)
{
	t_map	*local_map;

	local_map = (t_map *)malloc(sizeof(t_map));
	if (!local_map)
		exit_error(ERROR_MALLOC, errno, cube);
	return (local_map);
}
