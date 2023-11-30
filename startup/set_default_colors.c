/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:41:57 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/30 14:45:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	set_default_colors(t_map *map)
{
	t_color		tmp_color;

	tmp_color.b = DEFAULT_CEILING_B;
	tmp_color.g = DEFAULT_CEILING_G;
	tmp_color.r = DEFAULT_CEILING_R;
	map->texture.celing = tmp_color;
	tmp_color.b = DEFAULT_FLOOR_B;
	tmp_color.g = DEFAULT_FLOOR_G;
	tmp_color.r = DEFAULT_FLOOR_R;
	map->texture.floor = tmp_color;
}
