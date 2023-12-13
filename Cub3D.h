/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:19:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 17:46:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs/define.h"
# include "libft_def/libft.h"
# include "libs/structs.h"
# include "sys/errno.h"
# include <mlx.h>

//EXTRAS
//---------------------------------------------------------------------------

void		exit_error(char *s, int code, t_cube *cube);
void		free_cube(t_cube *cube);
t_fd		open_fd(t_path file, t_cube *cube);
void		free_split(char **split);
void		matrix_dimension(char **arr, int *rows, int *cols);
int			**to_int_ar(char **map, int rows, int cols, t_cube *cube);
//---------------------------------------------------------------------------

//STARTUP
//---------------------------------------------------------------------------

t_cube		*init(t_path file);
t_cube		*init_cube(t_cube *cube, t_path file);
t_map		*init_map(t_cube	*cube);
t_player	*init_player(t_cube	*cube);
t_mlx_img	*init_mlx_img(t_cube *cube);
t_point		*store_map_line(char *s, t_cube *cube);
t_point		**increase_map_size(int size, t_point **map, t_cube *cube);
t_point		**store_map(char **raw_map, t_cube *cube);
void		set_default_colors(t_map *map);
//---------------------------------------------------------------------------

//PARSE
//---------------------------------------------------------------------------

t_bool		check_argv(const char *s);
t_bool		parse(int argc, char **argv);
//---------------------------------------------------------------------------

//CHECKER
//---------------------------------------------------------------------------

t_bool		check_color(char **dump, int lines, t_cube *cube);
t_bool		check_texture(char **dump, int lines, t_cube *cube);
t_bool		check_map(char **dump);
t_bool		is_map_closed(char **map);
char		**get_map(char **dump, int n_lines, t_cube *cube);
void		check_fill_file(t_cube *cube, t_path path);
//---------------------------------------------------------------------------

//MLX
//---------------------------------------------------------------------------

void		mlx_open_win(t_cube *cube);
void		draw_background(t_cube *cube);
void		mlx_start(t_cube *cube);
void		init_img(t_cube *cube);
void		put_img(t_cube *cube, t_img img, int x, int y);
void		mlx_point_draw(t_cube *cube, int x, int y, t_color input_color);
void		draw(t_cube *cube);
t_img		*open_texture(t_path path, t_cube *cube);
void		fill_window(t_color color, t_vector2D start, t_vector2D end,
				t_cube *cube);

//---------------------------------------------------------------------------

//HOOKS
//---------------------------------------------------------------------------

void		movement_hook(t_cube *cube, t_bool	is_forward);
void		rotate_hook(t_cube *cube, t_bool is_right);
int			close_hook(t_cube *cube);
void		setup_hooks(t_cube *cube);

//PLAYER
//---------------------------------------------------------------------------

void		init_player_pos(t_cube *cube, char **map);
//---------------------------------------------------------------------------

//RAYCASTING
//---------------------------------------------------------------------------

//void		cast_ray(t_cube *cube);
void		raycasting(t_cube *cube);
double		calc_distance_to_wall(t_vector2D p_of_colision, double dist,
				t_cube *cube);
double		calc_wall_height(double side_dist);
void		draw_wall(double wall_height, int column, t_cube *cube);
//---------------------------------------------------------------------------

#endif