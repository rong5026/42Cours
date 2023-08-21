# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 22:29:25 by hong-yeongh       #+#    #+#              #
#    Updated: 2023/08/21 18:37:46 by hong-yeongh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a

CC = cc 
CFLAGS = -Wextra -Werror -Wall

LINKING_FLAGS = -lreadline -L/opt/homebrew/opt/readline/lib
COMFILE_FLAGS = -I/opt/homebrew/opt/readline/include

DIR_H = ./includes/
DIR_S = ./src/

SRC =	main.c

SRCS = $(addprefix $(DIR_S), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
