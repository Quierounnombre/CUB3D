/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:19:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 14:54:04 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs/define.h"
# include "libs/structs.h"
# include "sys/errno.h"
# include <mlx.h>

//EXTRAS
//---------------------------------------------------------------------------

void	exit_error(char *s, int code, t_cube *cube);
void	free_cube(t_cube	*cube);
//---------------------------------------------------------------------------

//STARTUP
//---------------------------------------------------------------------------

t_cube	*init(void);
t_map	*init_map(t_cube	*cube);
t_cube	*init_cube(t_cube	*cube);
t_cam	*init_cam(t_cube	*cube);
//---------------------------------------------------------------------------

#endif