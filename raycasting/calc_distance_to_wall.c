/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance_to_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:10:23 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:25:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

double	calc_distance_to_wall(t_vector2D p_of_colision, double dist,
			t_cube *cube)
{
	double	l_of_side;
	double	r_dist;

	l_of_side = p_of_colision.y - cube->player->pos.y;
	r_dist = ft_pythagoras(0, l_of_side, dist);
	return (r_dist);
}
