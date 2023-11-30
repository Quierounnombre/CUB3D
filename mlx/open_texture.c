/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:43 by alfgarci          #+#    #+#             */
/*   Updated: 2023/11/09 13:40:47 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_img	*open_texture(t_path path, t_cube *cube)
{
	t_img	img;

	img = mlx_xpm_file_to_image(cube->mlx, path, WIDTH_TEXTURE, HEIGHT_TEXTURE);
	if (img == 0)
		exit_error(ERROR_OPEN_TEXTURE, errno, cube);
	return (img);
}