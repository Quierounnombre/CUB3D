/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:51:42 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:14:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	rotate_hook(t_cube *cube, t_bool is_right)
{
	int		dir;
	double	r_angle;

	dir = 1;
	if (!is_right)
		dir = -1;
	r_angle = \
	(dir * GRADES_TO_RAD) * PLAYER_ROTATE_SPEED;
	r_angle += cube->player->angle;
	if (r_angle < 0)
		r_angle += (2 * M_PI);
	if (r_angle > (2 * M_PI))
		r_angle -= (2 * M_PI);
	cube->player->angle = r_angle;
	draw(cube);
}
