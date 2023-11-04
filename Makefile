# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:36:09 by alfgarci          #+#    #+#              #
#    Updated: 2023/11/04 13:36:10 by alfgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ED		=\033[1;31m
GREEN	=\033[1;32m
YELLOW	=\033[1;33m
NC		=\033[0m

#---cub3d-------------------------------
NAME 	=	cub3d
	#---SRC
EXTRA_DIR	=	extra
STARTUP_DIR	=	sturtup
SRC 	=	${STARTUP_DIR}/init.c \
			${EXTRA_DIR}/exit_error.c 

	#---OBJ
OBJ 	=	${SRC:.c=.o}
	#---INC
INC 	=	.

#---LIBFT-------------------------------
LIBFT_DIR	=	libft_def
LIBFT_NAME	=	ft_def
	#---INC
LIBFT_INC	= ${LIBFT_DIR}

#---MATH--------------------------------
MATH_NAME	=	m

CC			=	cc
C_FLAGS		=	-Werror -Wextra -Wall
LIB_FLAGS	=	-L${LIBFT_DIR} -l${LIBFT_NAME} -l${MATH_NAME}
H_FLAGS		=	-I${INC} -I${LIBFT_INC}
FLAGS		=	${C_FLAGS} ${LIB_FLAGS}

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
		@make re -s -C ${MLX_DIR}

.PHONY:	all clean fclean re