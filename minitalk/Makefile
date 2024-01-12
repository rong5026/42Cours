# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 16:29:21 by yeohong           #+#    #+#              #
#    Updated: 2023/06/03 14:21:24 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = MINITALK

SERVER = server
CLIENT = client

INCFLAGS = -I./libft

LIBFT_PATH = ./libft/
LIBFT_FILES = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_atoi.c ft_strlen.c
LIBFT_SRCS= $(addprefix $(LIBFT_PATH), $(LIBFT_FILES))
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

SRC_PATH = ./src

SERVER_SRCS = ./src/server.c
CLIENT_SRCS = ./src/client.c

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)

SERVER_SRCS_BONUS	= ./src/server_bonus.c
CLIENT_SRCS_BONUS	= ./src/client_bonus.c

SERVER_OBJS_BONUS	= $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS	= $(CLIENT_SRCS_BONUS:.c=.o)

ifdef BONUS
	SERVER_OBJECTS 	= $(SERVER_OBJS_BONUS)
	CLIENT_OBJECTS 	= $(CLIENT_OBJS_BONUS)
else
	SERVER_OBJECTS	= $(SERVER_OBJS)
	CLIENT_OBJECTS	= $(CLIENT_OBJS)
endif

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(SERVER): $(LIBFT_OBJS) $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

$(CLIENT): $(LIBFT_OBJS) $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

$(NAME): $(SERVER) $(CLIENT)
	
bonus:
	$(MAKE) BONUS=1 all

clean:
	$(RM) $(LIBFT_OBJS) 
	$(RM) $(SERVER_OBJS) $(SERVER_OBJS_BONUS) 
	$(RM) $(CLIENT_OBJS) $(CLIENT_OBJS_BONUS)
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	
fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: fclean all clean re