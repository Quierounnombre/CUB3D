/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_dimensions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:10:58 by vicgarci          #+#    #+#             */
/*   Updated: 2024/01/31 20:05:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

char	*look_for_line(t_fd fd, t_cube *cube, int advance_n_lines)
{
	char	*s;

	while (advance_n_lines)
	{
		s = ft_get_next_line(fd);
		if (!s)
			exit_error(ERROR_OPEN_TEXTURE, errno, cube);
		free(s);
		advance_n_lines--;
	}
	return (s);
}
