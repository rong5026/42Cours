NAME = bsq
SRCS = src/basic.c src/dp.c src/free.c src/main.c src/map_create.c src/map_init.c src/valid.c src/stdread.c
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
