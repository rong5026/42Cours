# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 18:03:18 by yeohong           #+#    #+#              #
#    Updated: 2022/10/16 18:21:17 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c 
OBJS = $(SRCS:.c=.o)
TARGET = libft.a
INCLUDE = ./includes/

all : $(TARGET)

$(TARGET) : $(OBJS) 
	ar rc $(TARGET) $(OBJS)

.c.o :
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I $(INCLUDE)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re

