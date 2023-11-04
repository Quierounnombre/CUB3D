/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:16:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 14:53:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_cube	*init_cube(t_cube *cube)
{
	t_cube	*local_cube;

	local_cube = (t_cube *)malloc(sizeof(t_cube));
	if (!local_cube)
		exit_error(ERROR_MALLOC, errno, cube);
	return (local_cube);
}
