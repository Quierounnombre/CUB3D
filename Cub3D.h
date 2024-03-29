/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:19:38 by vicgarci          #+#    #+#             */
/*   Updated: 2024/03/07 19:33:30 by alfgarci         ###   ########.fr       */
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
void		init_texture(t_texture *texture, t_cube *cube);
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
t_bool		check_pos(char **dump);
int			map_line(char **dump);
int			get_max_len_line(char **dump, int map_lines);
t_bool		is_map_closed(char **map);
char		**get_map(char **dump, int map, int max_len_line, t_cube *cube);
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
void		fill_window(t_color color, t_vector2D start, t_vector2D end,
				t_cube *cube);
void		ft_pixel_put(t_mlx_img	*img, int x, int y, unsigned int color);
void		open_texture(t_path path, t_cube *cube, t_direction dir,
				t_texture *texture);
t_color		int_to_t_color(int color);
void		draw_wall(t_ray_info *ray, t_cube *cube);
void		draw_texture(t_ray_info *ray, t_cube *cube, t_texture *texture);
void		draw_simple_wall(t_cube *cube, int column, double wall_height);
t_color		get_color_in_texture(t_texture *texture, t_ray_info *ray);

//---------------------------------------------------------------------------

//HOOKS
//---------------------------------------------------------------------------

void		movement_hook_vertical(t_cube *cube, t_bool is_forward);
void		movement_hook_horizontal(t_cube *cube, t_bool is_right);
void		rotate_hook(t_cube *cube, t_bool is_right);
int			close_hook(t_cube *cube);
void		setup_hooks(t_cube *cube);

//PLAYER
//---------------------------------------------------------------------------

void		init_player_pos(t_cube *cube, char **map);
//---------------------------------------------------------------------------

//RAYCASTING
//---------------------------------------------------------------------------

t_ray		*init_ray(t_cube *cube, int x);
void		raycasting(t_cube *cube);
double		calc_distance_to_wall(t_vector2D p_of_colision, double dist,
				t_cube *cube);
double		calc_wall_height(double side_dist);
t_vector2D	calc_wall_ratios(t_texture *texture, t_vector2D pos);
void		dda(t_cube *cube, t_ray *ray);
double		determine_impact_point(t_ray *ray, t_cube *cube);
double		calc_perp_wall_dist(t_ray *ray);
t_ray_info	init_ray_info(t_ray *ray, int colum, t_cube *cube);
//---------------------------------------------------------------------------

#endif