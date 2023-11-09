/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:16 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:52:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	char	**map;
	int i = -1;

	cube = NULL;
	if (parse(argc, argv))
	{
		cube = init(*argv);
		map = check_file(cube, argv[1]);
		while (map[++i])
			ft_printf("%s\n", map[i]);
		free(cube);
	}
	else
		exit_error(ERROR_PARSE, errno, cube);
}


