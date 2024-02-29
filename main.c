/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:16 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/29 15:13:21 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	cube = NULL;
	if (parse(argc, argv))
	{
		cube = init(*argv);
		check_fill_file(cube, argv[1]);
		draw(cube);
		mlx_loop(cube->mlx);
		free_cube(cube);
	}
	else
		exit_error(ERROR_PARSE, errno, cube);
}
