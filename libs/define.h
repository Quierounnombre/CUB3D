/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:25 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/04 17:38:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Parse info

# define WALL 1
# define EMPTY 0
# define WEST 2
# define SOUTH 3
# define NORTH 4
# define EAST 5
# define VOID_IN_MAP 6
# define END_OF_MAP 7

//Error msg

# define ERROR_MSG "Error\n"
# define ERROR_MALLOC "Malloc has fail :(\n"
# define ERROR_OPEN "Open has fail :(\n"
# define ERROR_PARSE "There are numerous reasons why this error message could \
apear but mainly, the user has submited a wrong formated file or didnt submit \
the right number of files in the first place (ONLY 1, NOT 0, NOT 2).\n"

//Size of a piece of wall

# define DIM_X	64
# define DIM_Y	64

#endif