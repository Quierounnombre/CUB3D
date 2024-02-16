/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:43 by alfgarci          #+#    #+#             */
/*   Updated: 2024/01/24 16:25:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_img	open_texture(t_path path, t_cube *cube, char dir)
{
	t_img	img;

	img = NULL;
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
	printf("%s\n", path);
	printf("%p\n%p\n", &cube->map->east.width, &cube->map->east.height);
	printf("%p\n", cube->mlx);
	if (img == NULL)
		exit_error(ERROR_OPEN_TEXTURE, errno, cube);
	return (img);
}
