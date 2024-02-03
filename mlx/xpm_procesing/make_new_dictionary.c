/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:39:36 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 10:45:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	make_new_dictionary(t_cube *cube, t_texture *texture)
{
	if (!ft_lstmngnew(NULL, &(texture->color_dictionary)))
		exit_error(ERROR_MALLOC, errno, cube);
}
