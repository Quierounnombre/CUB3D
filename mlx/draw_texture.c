/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:17:27 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/07 17:16:55 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static double	cacl_per(int start, int end, int valor)
{
	double	per;
	double	range;

	range = end - start;
	per = (valor - start) / range;
	return (per);
}

void	draw_texture(t_ray_info *ray, t_cube *cube, t_texture *texture)
{
	double	window_dimension;
	int		start_of_draw;
	int		end_of_draw;
	t_color	color;
	int		tmp;

	window_dimension = (HEIGHT - ray->wall_height) / SPLIT_THE_WIN;
	start_of_draw = window_dimension;
	end_of_draw = window_dimension + ray->wall_height;
	tmp = start_of_draw;
	while (start_of_draw <= end_of_draw - 1)
	{
		ray->wall_ratios.x = cacl_per(tmp, end_of_draw, start_of_draw);
		color = get_color_in_texture(texture, ray);
		mlx_point_draw(cube, ray->column, start_of_draw, color);
		start_of_draw++;
	}
}
