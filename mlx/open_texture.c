/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:33:19 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 17:08:37 by vicgarci         ###   ########.fr       */
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
		texture->img = open_xpm(cube->mlx, path, &(cube->map->north));
	if (dir == SOUTH)
		texture->img = open_xpm(cube->mlx, path, &(cube->map->south));
	if (dir == WEST)
		texture->img = open_xpm(cube->mlx, path, &(cube->map->west));
	if (dir == EAST)
		texture->img = open_xpm(cube->mlx, path, &(cube->map->east));
	if (texture->img == NULL)
		exit_error(ERROR_OPEN_TEXTURE, errno, cube);
	texture->img->adres = mlx_get_data_addr(texture->img->img,
			&texture->img->bits_per_pixel, &texture->img->line,
			&texture->img->endian);
}
