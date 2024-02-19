/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:43 by alfgarci          #+#    #+#             */
/*   Updated: 2024/02/19 15:38:10 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static t_img	open_xpm(t_cube *cube, t_path path, t_texture *texture)
{
	t_img	img;

	img = NULL;
	img = mlx_xpm_file_to_image(cube->mlx, path, &(texture->width),
			&(texture->width));
	ft_printf("PATH %s", path);
	ft_printf("TXT %p\n", img);
	return (img);
}

void	open_texture(t_path path, t_cube *cube, t_direction dir,
		t_texture *texture)
{
	if (dir == NORTH)
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->north.width,
				&(cube->map->north.height));
	}
	else if (dir == SOUTH)
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->south.width,
				&cube->map->south.height);
	}
	else if (dir == WEST)
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->west.width,
				&cube->map->west.height);
	}
	else if (dir == EAST)
	{
		img = mlx_xpm_file_to_image(cube->mlx, path, &cube->map->east.width,
				&cube->map->east.height);
	}
	if (img == NULL)
		exit_error(ERROR_OPEN_TEXTURE, errno, cube);
	texture->img->adres = mlx_get_data_addr(texture->img->img,
			&texture->img->bits_per_pixel, &texture->img->line,
			&texture->img->endian);
}
