CC = gcc
FLAGS = -Wall -Wextra -Werror -g
HEAD_PUSH = push_swap.h
HEAD_CHECKER = checker.h
NAME_PUSH = push_swap
NAME_CHECKER = checker
SRC_PUSH = push_swap.c
SRC_CHECKER = checker.c
OBJECTS_PUSH = $(SRC_PUSH:.c=.o)
OBJECTS_CHECKER = $(SRC_CHECKER:.c=.o)

all: $(NAME)

$(NAME): checker push_swap

.c.o: $(HEAD_PUSH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

checker: $(OBJECTS_CHECKER)
	$(CC) -o $(NAME_CHECKER) -c $< -o $@

push_swap: $(OBJECTS_PUSH)
	$(CC) -o $(NAME_PUSH) -c $< -o $@

.PHONY: clean fclean all re checker push_swap