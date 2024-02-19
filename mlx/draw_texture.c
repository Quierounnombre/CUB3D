/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:17:27 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw_texture(t_ray_info *ray, t_cube *cube, t_texture *texture)
{
	int		pos_in_texture;
	double	window_dimension;
	int		start_of_draw;
	int		end_of_draw;
	t_color	color;

	window_dimension = (HEIGHT - ray->wall_height) / SPLIT_THE_WIN;
	start_of_draw = window_dimension;
	end_of_draw = window_dimension + ray->wall_height;
	pos_in_texture = 0;
	while (start_of_draw <= end_of_draw)
	{
		color = get_color_in_texture(texture, ray->wall_ratios, pos_in_texture);
		mlx_point_draw(cube, ray->column, start_of_draw, color);
		pos_in_texture++;
		start_of_draw++;
	}
}
