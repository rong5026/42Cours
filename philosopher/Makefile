# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 22:29:25 by hong-yeongh       #+#    #+#              #
#    Updated: 2023/08/13 00:34:29 by hong-yeongh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = philo

# INC 	= includes/philo.h

# SRC		=	src/actions.c\
# 			src/check_input.c\
# 			src/init.c\
# 			src/main.c\
# 			src/run.c\
# 			src/time.c\
# 			src/utils.c\

# CC 		= cc

# FLAGS	= -Wall -Wextra -Werror -pthread

# OBJS 	= $(SRC:.c=.o)

# $(NAME): $(OBJS)
# 	$(CC) $(FLAGS) $(SRC) -o $(NAME)

# all: $(NAME) $(OBJS) $(INC)

# %.o: %.c $(INC)
# 		$(CC) $(FLAGS) -c $< -o $@

# clean:
# 	rm -rf $(OBJS)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

CC = cc
CFLAGS = -Wextra -Werror -Wall

NAME = philo

DIR_H = ./includes/
DIR_S = ./src/

SRC =	action.c check_input.c free.c init.c main.c run.c time.c utils.c

SRCS = $(addprefix $(DIR_S), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
