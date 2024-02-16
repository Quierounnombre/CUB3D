/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:29 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/15 18:40:50 by alfgarci         ###   ########.fr       */
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

typedef struct s_vector2Dint
{
	int	x;
	int	y;
}	t_vector2Dint;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_texture
{
	t_img	img;
	int		width;
	int		height;
}	t_texture;

typedef struct t_map
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_color		celing;
	t_color		floor;
	t_color		wall_color;
	int			**map;
	int			height;
	int			width;
}	t_map;

typedef struct s_player
{
	double		angle;
	t_vector2D	dir;
	t_vector2D	plane;
	int			fov;
	t_vector2D	pos;
}	t_player;

typedef struct s_mlx_img
{
	t_img	img;
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

typedef struct s_ray
{
	t_vector2D		ray_dir;
	t_vector2D		delta;
	t_vector2D		step;
	t_vector2D		side;
	t_vector2Dint	map_cor;
	int				hit;
	int				side_hit;
	double			perp_wall_dist;
	int				line_height;
	char			wall_hit;
}	t_ray;

#endif