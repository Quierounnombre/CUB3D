/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:16:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:52:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	remove_dot_slash(t_path *file)
{
	(*file) += 2;
}

t_cube	*init_cube(t_cube *cube, t_path file)
{
	t_cube	*local_cube;
	t_path	local_file;

	local_cube = (t_cube *)malloc(sizeof(t_cube));
	if (!local_cube)
		exit_error(ERROR_MALLOC, errno, cube);
	remove_dot_slash(&file);
	local_file = ft_strdup(file);
	if (!local_file)
		exit_error(ERROR_MALLOC, errno, cube);
	local_cube->file = local_file;
	return (local_cube);
}
