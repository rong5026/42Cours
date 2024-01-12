# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 17:15:21 by yeohong           #+#    #+#              #
#    Updated: 2023/07/03 22:57:19 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
PRINTF_PATH = ./printf/libftprintf.a
GNL_PATH = ./get_next_line/gnl.a
LIBFT_PATH = ./libft/libft.a
MLX_PATH = ./mlx/libmlx.a
CC = cc # 제출할때 cc만
CFLAGS = -Wall -Wextra -Werror
M_CFILE = so_long.c read_file.c image.c move_key.c error.c map_check.c map_file.c
M_OBJ = ${M_CFILE:.c=.o}
B_CFILE = so_long.c read_file.c image.c move_key.c error.c map_check.c map_file.c
B_OBJ = ${B_CFILE:.c=.o}
LIBC =  -L./mlx -lmlx -framework OpenGL -framework Appkit
INCS = ${PRINTF_PATH} ${LIBFT_PATH} ${GNL_PATH} ${MLX_PATH}
ifdef BONUS
    OBJ = ${B_OBJ}
else
    OBJ = ${M_OBJ}
endif

.c.o:
	${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}
all : ${NAME}
${NAME} : ${OBJ}
	@make -C printf/
	@make -C libft/
	@make -C get_next_line/
	@make -C mlx/
	$(CC) $(CFLAGS) -o $(NAME) $(INCS) -I . $(LIBC) $(OBJ)
bonus :
	make BONUS=1 all
clean :
	@make -C printf/ clean
	@make -C libft/ clean
	@make -C get_next_line/ clean
	@make -C mlx/ clean
	rm -f ${B_OBJ} ${M_OBJ}
fclean : clean
	@make -C printf/ fclean
	@make -C libft/ fclean
	@make -C get_next_line/ fclean
	rm -f ${NAME}
re : clean all
	# @make -C printf/ re
	# @make -C libft/ re
	# @make -C get_next_line/ re
	# @make -C mlx/ re
	# make fclean
	# make all
.PHONY : all clean fclean re bonus
