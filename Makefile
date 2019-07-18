NAME = push_swap
NAME2 = checker

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC =	push_swap_f.c arrjoin.c str_splitspaces.c \
		push_swap.c
SRC2 =	ft_atoi.c \
		checker.c						

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -I$(INCLUDES) -c $(SRC)
	@$(CC) $^ -L./libft/ -lft -o $@
	@echo "$(NAME) created successfully"

$(NAME2): $(OBJ2)
	@make -C ./libft/
	@$(CC) -I$(INCLUDES) -c $(SRC2)
	@$(CC) $^ -L./libft/ -lft -o $@
	@echo "$(NAME2) created successfully"

%.o: %.c
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Erasing .o files in Push_Swap..."
	@rm -f $(OBJ) $(OBJ2)
	@echo "Done."

fclean: clean
	@make fclean -C ./libft/
	@echo "Erasing $(NAME)..."
	@rm -f $(NAME) $(NAME2)
	@echo "Done."

re: fclean all clean

.PHONY: all, clean, fclean, re