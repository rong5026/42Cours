# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 17:05:17 by yeohong           #+#    #+#              #
#    Updated: 2023/07/21 13:35:29 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC	= check_input.c error.c greedy_sort_utils_compare.c greedy_sort_utils_index.c greedy_sort_utils.c greedy_sort.c indexing.c node_set.c origin_sort.c parsing_input.c push_swap.c sorting.c swap_cmd.c swap_cmd1.c utils.c

LIBFT = libft/libft.a

OBJ	=$(SRC:.c=.o)

CC=	cc

RM=	rm -f

CFLAGS=	-Wall -Wextra -Werror

$(NAME):$(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:$(NAME)

clean:
	make clean -C libft
	${RM} $(OBJ) 

fclean: clean
	${RM} $(NAME) 

re:	fclean all


.PHONY:all clean fclean re
