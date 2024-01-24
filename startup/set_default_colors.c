/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:41:57 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 17:06:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	set_default_colors(t_map *map)
{
	t_color		tmp_color;

	tmp_color.b = DEFAULT_CEILING_B;
	tmp_color.g = DEFAULT_CEILING_G;
	tmp_color.r = DEFAULT_CEILING_R;
	map->celing = tmp_color;
	tmp_color.b = DEFAULT_FLOOR_B;
	tmp_color.g = DEFAULT_FLOOR_G;
	tmp_color.r = DEFAULT_FLOOR_R;
	map->floor = tmp_color;
	tmp_color.b = DEFAULT_WALL_B;
	tmp_color.g = DEFAULT_WALL_G;
	tmp_color.r = DEFAULT_WALL_R;
	map->wall_color = tmp_color;
}
