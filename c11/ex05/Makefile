# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 09:41:54 by yeohong           #+#    #+#              #
#    Updated: 2022/10/18 14:12:19 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = src/ft_atoi.c src/ft_putnbr.c src/ft_hong.c src/main.c
OBJS = $(SRCS:.c=.o)
INC = ./includes

all :$(NAME)

$(NAME) : $(OBJS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS)

.c.o :
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I $(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

