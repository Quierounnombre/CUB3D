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

t_image	*open_texture(t_path path, t_cube *cube)
{
	t_image	img;

	img = mlx_xpm_file_to_image(cube->mlx, path, WIDTH, HEIGHT);
	if (img == 0)
		exit_error("Fallo Textura, errno, cube");
	return (img);
}