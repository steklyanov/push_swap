CC = gcc
FLAGS = -Wall -Wextra -Werror -g
HEAD = printf.h
NAME = libftprintf.a
SRC = ft_printf.c\
	main.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(FLAGS) $(OBJECTS) 

.c.o: $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re