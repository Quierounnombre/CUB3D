/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:31:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Parse info

# define WALL '1'
# define EMPTY '0'
# define WEST 'W'
# define SOUTH 'S'
# define NORTH 'N'
# define EAST 'E'
# define VOID_IN_MAP 'v'

//Error msg

# define ERROR_MSG "Error\n"
# define ERROR_MALLOC "Malloc has fail :(\n"
# define ERROR_OPEN "Open has fail :(\n"
# define ERROR_PARSE "There are numerous reasons why this error message could \
apear but mainly, the user has submited a wrong formated file or didnt submit \
the right number of files in the first place (ONLY 1, NOT 0, NOT 2).\n"
# define ERROR_FORMAT ".cub file format error :(\n"
# define ERROR_WALLS "The map walls are not closed :(\n)"
# define ERROR_MLX_INIT "Can't start MLX\n"
# define ERROR_MLX_WIN "Can't start a new windows\n"
# define ERROR_MLX_IMG "Can't create a new img\n"
# define ERROR_MLX_PUT_IMG "Can't put img to win\n"
# define ERROR_OPEN_TEXTURE "Can't open texture\n"

//Size of a piece of wall

# define DIM_X	64
# define DIM_Y	64

//Conversion from º to rad

# define GRADES_TO_RAD 0.0174533

//MLX

# define WIDTH 1000
# define HEIGHT 1000
# define NAME "cub3D"
# define ENDIAN_CONVERSION 8

//Colors

# define DEFAULT_CEILING_B 255
# define DEFAULT_CEILING_G 0
# define DEFAULT_CEILING_R 0

# define DEFAULT_FLOOR_B 0
# define DEFAULT_FLOOR_G 255
# define DEFAULT_FLOOR_R 0

# define DEFAULT_WALL_B 0
# define DEFAULT_WALL_G 0
# define DEFAULT_WALL_R 255 

//Player

# define PLAYER_SPEED 0.2
# define PLAYER_ROTATE_SPEED 0.1
# define PLAYER_FOV 60
# define PLAYER_DEFAULT_ANGLE 0
# define PLAYER_DEFAULT_POS_X 0
# define PLAYER_DEFAULT_POS_Y 0

//KEYS

# define KEY_FORWARD 13 //w
# define KEY_BACKWARD 1 //s
# define KEY_ROTATE_RIGHT 2 //d
# define KEY_ROTATE_LEFT 0 //a
# define KEY_ESCAPE 53 //esc

#endif