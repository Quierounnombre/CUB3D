/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 13:40:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef int		t_point;
typedef void	*t_img;
typedef int		t_fd;
typedef char	*t_path;
typedef void	*t_win;
typedef void	*t_mlx;
typedef int		t_key;

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
	char		**map;
	int			height;
	int			width;
}	t_map;

typedef struct s_player
{
	double		angle;
	int			fov;
	t_vector2D	pos;
}	t_player;

typedef struct s_mlx_img
{
	t_img	*img;
	char	*adres;
	int		bits_per_pixel;
	int		line;
	int		endian;
}	t_mlx_img;

typedef struct s_cube
{
	t_path		file;
	t_map		*map;
	t_player	*player;
	t_win		win;
	t_mlx		mlx;
	t_mlx_img	*mlx_img;
}	t_cube;


#endif