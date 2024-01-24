/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 17:05:19 by vicgarci         ###   ########.fr       */
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

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	double	step_x;
	double	step_y;
	int		hit;
	int		side;
	double	side_x;
	double	side_y;
	double	perp_wall_dist;
	int		line_height;
}	t_ray;

#endif