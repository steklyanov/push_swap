# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 16:56:08 by mmraz             #+#    #+#              #
#    Updated: 2019/08/01 20:44:43 by mmraz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = gcc $(FLAGS)

FLAGS = -g -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC =	algorithm.c operations_2.c operations.c push_swap_f.c \
		validation.c arrjoin.c str_splitspaces.c \
		split_whitespaces_to_int.c ft_atoi_small.c scenarios.c push_swap.c
SRC2 =	algorithm.c operations_2.c operations.c push_swap_f.c \
		validation.c arrjoin.c str_splitspaces.c \
		split_whitespaces_to_int.c ft_atoi_small.c scenarios.c checker.c						

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) -I$(INCLUDES) -c $(SRC)
	$(CC) $^ -L./libft/ -lft -o $@

$(NAME2): $(OBJ2)
	make -C ./libft/
	$(CC) -I$(INCLUDES) -c $(SRC2)
	$(CC) $^ -L./libft/ -lft -o $@

%.o: %.c
	@$(CC) -o $@ -c $<

clean:
	make clean -C ./libft/
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME) $(NAME2)

re: fclean all clean

.PHONY: all, clean, fclean, re