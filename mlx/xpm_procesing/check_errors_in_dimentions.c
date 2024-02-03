/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_in_dimentions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:02:52 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 11:03:19 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	check_errors_in_dimentions(t_texture *texture, t_cube *cube)
{
	if (texture->width < MIN_TEXTURE_WIDTH)
		exit_error(ERROR_TEXTURE_DIMENTIONS, DEFAULT_ERROR_CODE, cube);
	if (texture->height < MIN_TEXTURE_HEIGHT)
		exit_error(ERROR_TEXTURE_DIMENTIONS, DEFAULT_ERROR_CODE, cube);
	if (texture->color_per_pixel < MIN_COLORS_PER_PIXEL)
		exit_error(ERROR_TEXTURE_DIMENTIONS, DEFAULT_ERROR_CODE, cube);
	if (texture->n_colors < MIN_NUMBER_OF_COLORS)
		exit_error(ERROR_TEXTURE_DIMENTIONS, DEFAULT_ERROR_CODE, cube);
}
