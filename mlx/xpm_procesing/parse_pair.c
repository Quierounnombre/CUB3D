/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:42:27 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:46:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static char	get_key_from_string(t_cube *cube, char *s)
{
	if (*s)
		s++;
	if (!*s)
	{
		s--;
		free(s);
		exit_error(ERROR_BAD_XPM, DEFAULT_ERROR_CODE, cube);
	}
	return (*s);
}

static int	extract_color_from_string(t_cube *cube, char *s)
{
	int		i;
	int		tmp;

	i = 0;
	while (*s && i < ADVANCE_TO_COLOR_STRING)
	{
		s++;
		i++;
	}
	if (!*s || i < ADVANCE_TO_COLOR_STRING)
	{
		free(s);
		exit_error(ERROR_BAD_XPM, DEFAULT_ERROR_CODE, cube);
	}
	i = 0;
	while (s[i])
	{
		if (!ft_is_mayus_or_num(s[i]))
		{
			free(s);
			exit_error(ERROR_BAD_XPM, DEFAULT_ERROR_CODE, cube);
		}
		i++;
	}
	tmp = ft_atoi_base(s, HEXA_MAYUS_BASE);
	return (tmp);
}

static t_color	convert_from_complex_int_to_rgb(int color)
{
	t_color	tmp;
	int		color_copy;

	color_copy = color;
	color_copy = color_copy << ENDIAN_CONVERSION;
	color_copy = color_copy >> 3 * ENDIAN_CONVERSION;
	tmp.g = color_copy;
	tmp.b = color_copy;
	color_copy = color;
	color_copy = color_copy >> ENDIAN_CONVERSION;
	color_copy = color_copy << 3 * ENDIAN_CONVERSION;
	color_copy = color_copy >> 3 * ENDIAN_CONVERSION;
	tmp.g = color_copy;
	color_copy = color;
	color_copy = color_copy << 3 * ENDIAN_CONVERSION;
	color_copy = color_copy >> 3 * ENDIAN_CONVERSION;
	tmp.r = color_copy;
	return (tmp);
}

static void	load_content_into_node(t_list *lst, t_color_key pair)
{
	t_color_key	*lst_content;

	lst_content = lst->content;
	lst_content->key = pair.key;
	lst_content->value = pair.value;
}

void	parse_pair(t_cube *cube, char *s, t_list *lst)
{
	t_color_key	pair;
	int			extracted_color;

	remove_quotes(s);
	pair.key = get_key_from_string(cube, s);
	extracted_color = extract_color_from_string(cube, s);
	pair.value = convert_from_complex_int_to_rgb(extracted_color);
	load_content_into_node(lst, pair);
}
