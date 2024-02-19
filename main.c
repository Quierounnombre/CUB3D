/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:16 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/17 17:59:49 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	tmp_ver_caracteristicas(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	printf("Height Map: %d\n", cube->map->height);
	printf("Widht Map: %d\n", cube->map->width);
	while (++i < cube->map->height)
	{
		j = -1;
		while (++j < cube->map->width)
		{
			ft_printf("%d", cube->map->map[i][j]);
		}
		ft_printf("\n");
	}

	printf("Angle Player: %f\n", cube->player->angle);
	printf("Pos Player  x: %f  y: %f\n",
		cube->player->pos.x, cube->player->pos.y);
	printf("DIR VEC     x: %f  y: %f\n",
		cube->player->dir.x, cube->player->dir.y);
	printf("PLANE VEC   x: %f  y: %f\n",
		cube->player->plane.x, cube->player->plane.y);
}

int	main(int argc, char **argv)
{
	t_cube	*cube;

	cube = NULL;
	if (parse(argc, argv))
	{
		cube = init(*argv);
		check_fill_file(cube, argv[1]);
		tmp_ver_caracteristicas(cube);
		draw(cube);
		mlx_loop(cube->mlx);
		free_cube(cube);
	}
	else
		exit_error(ERROR_PARSE, errno, cube);
}


