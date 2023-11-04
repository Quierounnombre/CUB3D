/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:57:34 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 16:22:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_bool	parse(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	argv++;
	if (!check_argv(*argv))
		return (false);
	return (true);
}
