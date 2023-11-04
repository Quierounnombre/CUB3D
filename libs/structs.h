/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 14:07:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft_def/libft.h"

typedef int		t_point;
typedef void	*t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_color	celing;
	t_color	floor;
}	t_texture;

typedef struct t_map
{
	t_texture	texture;
	t_point		**map;
}	t_map;

typedef struct s_cam
{
	int			angel;
	int			fov;
	t_vector2D	pos;
}	t_cam;

typedef struct s_cube
{
	t_map	*map;
	t_cam	*cam;
}	t_cube;


#endif