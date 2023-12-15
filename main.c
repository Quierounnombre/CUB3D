/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:16 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/12 18:10:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	int		i;

	i = 0;

	cube = NULL;
	if (parse(argc, argv))
	{
		cube = init(*argv);
		check_fill_file(cube, argv[1]);
		printf("Altura Mapa: %d\n", cube->map->height);
		printf("Anchura Mapa: %d\n", cube->map->width);
		init_player_pos(cube);
		printf("Altura Mapa: %d\n", cube->map->height);
		printf("Anchura Mapa: %d\n", cube->map->width);
		while (cube->map->map[++i])
			ft_printf("%s\n", cube->map->map[i]);
		printf("Angulo Player: %f\n", cube->player->angle);
		printf("Pos Player x: %f  y: %f\n", cube->player->pos.x, cube->player->pos.y);
		draw(cube);
		cast_ray(cube);
		mlx_loop(cube->mlx);
		free_cube(cube);
	}
	else
		exit_error(ERROR_PARSE, errno, cube);
}


