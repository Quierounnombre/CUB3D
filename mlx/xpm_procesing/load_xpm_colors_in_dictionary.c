/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm_colors_in_dictionary.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:30:05 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:44:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	load_xpm_colors_in_dictionary(t_fd fd, t_cube *cube,
			t_texture *texture)
{
	int		remaining_keys_in_xpm;
	char	*s;

	make_new_dictionary(cube, texture);
	remaining_keys_in_xpm = texture->n_colors;
	while (remaining_keys_in_xpm)
	{
		s = look_for_line(fd, cube, ADVANCE_TO_NEXT_COLOR);
		add_new_key_to_dic(cube, texture, s);
		free(s);
		remaining_keys_in_xpm--;
	}
}
