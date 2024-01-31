/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:55:19 by vicgarci          #+#    #+#             */
/*   Updated: 2024/01/31 20:36:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	load_texture(t_cube *cube, t_texture *texture)
{
	t_fd	fd;
	char	*s;

	fd = open_fd(texture->file, cube);
	s = look_for_line(fd, cube, ADVANCE_TO_DIMENSIONS_IN_XPM);
	set_texture_dimentions(s, texture, cube);
	free(s);
}
