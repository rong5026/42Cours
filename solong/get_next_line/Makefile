# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 15:13:55 by yeohong           #+#    #+#              #
#    Updated: 2023/06/28 15:13:57 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CSRCS = get_next_line.c get_next_line_utils.c
COBJS = ${CSRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${COBJS}
	ar rc $@ ${COBJS}

clean :
	rm -f ${COBJS}

fclean : clean
	rm -f ${NAME}

re :
	make fclean
	make all

.PHONY : all clean fclean re