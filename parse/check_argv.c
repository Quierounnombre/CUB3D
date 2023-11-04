/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:53:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:36:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	check_argv(const char *s)
{
	char	*c;
	t_fd	fd;

	c = ft_strchr(s, '.');
	if (!c)
		return (false);
	c++;
	if (!ft_strcmp(c, "cub"))
		return (false);
	fd = open_fd((t_path)s, NULL);
	close(fd);
	return (true);
}
