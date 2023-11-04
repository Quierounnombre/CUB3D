/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:42:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 13:55:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	exit_error(char *s, int code)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	exit(code);
}
