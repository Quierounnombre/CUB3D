/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:16 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/30 17:04:08 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	int i = -1;

	cube = NULL;
	if (parse(argc, argv))
	{
		cube = init(*argv);
		cube->map->map = check_file(cube, argv[1]);
		init_player_pos(cube);
		/*
		while (cube->map->map[++i])
			ft_printf("%s\n", cube->map->map[i]);
		printf("Angulo Player: %f\n", cube->player->angle);
		printf("Pos Player x: %f  y: %f\n", cube->player->pos.x, cube->player->pos.y);
		*/
		draw(cube);
		mlx_loop(cube->mlx);
		free_cube(cube);
	}
	else
		exit_error(ERROR_PARSE, errno, cube);
}


