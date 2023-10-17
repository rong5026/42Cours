# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 22:41:49 by hong-yeongh       #+#    #+#              #
#    Updated: 2023/10/18 01:16:01 by hong-yeongh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wextra -Werror -Wall -g -fsanitize=thread

DIR_H = ./includes/
DIR_S = ./src/


SRC = main_bonus.c check_input_bonus.c init_bonus.c monitor_bonus.c run_bonus.c message_bonus.c action_bonus.c free_bonus.c utils_bonus.c

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
