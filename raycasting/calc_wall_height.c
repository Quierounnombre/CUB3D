/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:00 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:48:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

double	calc_wall_height(double side_dist)
{
	double	r_wall_height;

	r_wall_height = HEIGHT / side_dist;
	return (r_wall_height);
}
