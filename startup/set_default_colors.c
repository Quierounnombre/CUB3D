/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:41:57 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/09 12:20:06 by alfgarci         ###   ########.fr       */
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
