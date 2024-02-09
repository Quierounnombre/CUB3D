/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:55:19 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/04 16:43:08 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	load_xpm(t_cube *cube, t_texture *texture)
{
	t_fd	fd;
	char	*s;

	fd = open_fd(texture->file, cube);
	s = look_for_line(fd, cube, ADVANCE_TO_DIMENSIONS_IN_XPM);
	set_xpm_dimentions(s, texture, cube);
	free(s);
	check_errors_in_dimentions(texture, cube);
	load_xpm_colors_in_dictionary(fd, cube, texture);
}
