# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:36:09 by alfgarci          #+#    #+#              #
#    Updated: 2023/11/30 15:09:31 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ED		=\033[1;31m
GREEN	=\033[1;32m
YELLOW	=\033[1;33m
NC		=\033[0m

#---cub3d-------------------------------
NAME 	=	cub3d

#---SRC

FILES_STARTUP =	init_cam \
				init_cube \
				init_map \
				init_mlx_img \
				set_default_colors \
				init \

STARTUP_DIR = ./startup/
SRCS_STARTUP = $(addprefix $(STARTUP_DIR), $(addsuffix .c, $(FILES_STARTUP)))

FILES_CHECKER =	check_color\
				check_file \
				check_map \
				check_textures \
				check_walls \

CHECKER_DIR = ./checker/
SRCS_CHECKER = $(addprefix $(CHECKER_DIR), $(addsuffix .c, $(FILES_CHECKER)))

FILES_EXTRAS =	exit_error \
				free_cube \
				open_fd \
				utils \

EXTRAS_DIR = ./extras/
SRCS_EXTRAS = $(addprefix $(EXTRAS_DIR), $(addsuffix .c, $(FILES_EXTRAS)))

FILES_PARSE =	parse \
				check_argv \

PARSE_DIR = ./parse/
SRCS_PARSE = $(addprefix $(PARSE_DIR), $(addsuffix .c, $(FILES_PARSE)))

FILES_MLX =	mlx_open_win \
			mlx_start \
			init_img \
			mlx_point_draw \
			draw \
			put_img \
			fill_window \

MLX_DIR = ./mlx/
SRCS_MLX = $(addprefix $(MLX_DIR), $(addsuffix .c, $(FILES_MLX)))

SRC 	=	$(SRCS_STARTUP) \
			$(SRCS_EXTRAS) \
			$(SRCS_PARSE) \
			$(SRCS_CHECKER) \
			$(SRCS_MLX) \
			main.c \

#---OBJ
OBJ 	=	${SRC:.c=.o}
#---INC
INC 	=	.

#---LIBFT-------------------------------
LIBFT_DIR	=	libft_def
LIBFT_NAME	=	ft
#---INC
LIBFT_INC	= ${LIBFT_DIR}

#---MATH--------------------------------
MATH_NAME	=	m

CC			=	cc
C_FLAGS		=	-Werror -Wextra -Wall
MLXFLAGS = -I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGL -framework Appkit
LIB_FLAGS	=	-L${LIBFT_DIR} -l${LIBFT_NAME} -l${MATH_NAME}
H_FLAGS		=	-I${INC} -I${LIBFT_INC}
FLAGS		=	${C_FLAGS} ${LIB_FLAGS} $(MLXFLAGS)

#---RECIPES------------------------------
%.o : %.c
	@${CC} ${C_FLAGS} ${H_FLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJ}
		@echo "${RED}Compiling Libft...${NC}"
		@make -s -C ${LIBFT_DIR}
		@echo "${RED}Compiling cub3d...${NC}"
		@${CC} ${FLAGS} ${OBJ} -o ${NAME}
		@echo "${GREEN}${NAME} READY!${NC}"

clean:
		@make clean -s -C ${LIBFT_DIR}
		@rm -f ${OBJ}
		@echo "${YELLOW}OBJS REMOVED!${NC}"

fclean:		clean
		@make fclean -s -C ${LIBFT_DIR}
		@rm -f ${NAME}
		@echo "${YELLOW}${NAME} REMOVED!${NC}"

re:		fclean all

.PHONY:	all clean fclean re