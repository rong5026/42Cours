# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 22:29:25 by hong-yeongh       #+#    #+#              #
#    Updated: 2023/10/18 01:15:23 by hong-yeongh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wextra -Werror -Wall -g -fsanitize=thread

DIR_H = ./includes/
DIR_S = ./src/

SRC =	action.c check_input.c free.c init.c main.c run.c time.c utils.c get_set.c

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
