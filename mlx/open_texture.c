/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:43 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/17 17:51:03 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_img	open_texture(t_path path, t_cube *cube, char dir)
{
	t_img	img;

	img = NULL;
	if (dir == 'N')
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &(cube->map->north.width) ,
			&(cube->map->north.height));
	}
	else if (dir == 'S')
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->south.width ,
			&cube->map->south.height);
	}
	else if (dir == 'W')
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->west.width ,
			&cube->map->west.height);
	}
	else if (dir == 'E')
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->east.width ,
			&cube->map->east.height);
	}
	if (img == NULL)
		exit_error(ERROR_OPEN_TEXTURE, errno, cube);
	return (img);
}
