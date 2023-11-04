/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:35:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 13:49:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_cube	*init(void)
{
	t_cube	*local_cube;

	local_cube = (t_cube *)malloc(sizeof(t_cube));
	if (!local_cube)
		exit_error(ERROR_MALLOC, errno);
	return (local_cube);
}
