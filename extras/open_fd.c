/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:01:12 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:31:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_fd	open_fd(t_path file, t_cube *cube)
{
	t_fd	local_fd;

	local_fd = open(file, O_RDONLY | O_NOFOLLOW | O_NONBLOCK);
	if (local_fd < 0)
		exit_error(ERROR_OPEN, errno, cube);
	return (local_fd);
}
