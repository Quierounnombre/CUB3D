/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xpm_dimentions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:05:54 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:33:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static char	*advance_to_next_number(char *s, t_cube *cube)
{
	if (*s == ' ')
		s++;
	while (*s != ' ' && *s)
		s++;
	if (!*s)
		exit_error(ERROR_BAD_XPM, DEFAULT_ERROR_CODE, cube);
	return (s);
}

void	set_xpm_dimentions(char *s, t_texture *texture, t_cube *cube)
{
	remove_quotes(s);
	texture->width = ft_atoi(s);
	s = advance_to_next_number(s, cube);
	texture->height = ft_atoi(s);
	s = advance_to_next_number(s, cube);
	texture->n_colors = ft_atoi(s);
	s = advance_to_next_number(s, cube);
	texture->n_colors = ft_atoi(s);
}
