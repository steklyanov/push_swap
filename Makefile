CC = gcc
FLAGS = -Wall -Wextra -Werror -g
HEAD_PUSH = push_swap.h
HEAD_CHECKER = checker.h
NAME_PUSH = push_swap
NAME_CHECKER = checker
SRC_PUSH = push_swap.c
SRC_CHECKER = ft_atoi.c checker.c 
OBJECTS_PUSH = $(SRC_PUSH:.c=.o)
OBJECTS_CHECKER = $(SRC_CHECKER:.c=.o)

all: $(NAME_CHECKER)

# $(NAME): checker push_swap

.c.o: $(HEAD_PUSH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	/bin/rm -f $(OBJECTS_PUSH) $(OBJECTS_CHECKER)

fclean: clean
	/bin/rm -f $(NAME_PUSH) $(NAME_CHECKER)

# re: fclean all

# checker: $(OBJECTS_CHECKER)
# 	$(CC) -o $(NAME_CHECKER) -c  -o $< $@

# push_swap: $(OBJECTS_PUSH)
# 	$(CC) -o $(NAME_PUSH) -c $< -o $@

$(NAME_CHECKER): $(OBJECTS_CHECKER)
	$(CC) $(FLAGS) $(HEAD_PUSH) -c $(SRC_CHECKER) -o $@

.PHONY: clean fclean all re checker push_swap