/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:16 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/09 15:04:46 by vicgarci         ###   ########.fr       */
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
		mlx_loop(cube->mlx);
		free_cube(cube);
	}
	else
		exit_error(ERROR_PARSE, errno, cube);
}


