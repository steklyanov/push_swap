/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:01:13 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/23 14:43:16 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack t_stack;

struct		s_stack
{
	int		len;
	int		*stack;
};

int		ft_atoi_small(const char *str);
int     ft_isspace(char s);
int		ft_isdigit(int c);
void	ft_print_usage();
int		ft_check_equal(t_stack *stack);
void    sort_three(t_stack *stack_a);
int		choose_sort_three(t_stack *stack_a);
void    swap_one(t_stack *stack_a);
char	*concat_all(int argc, char **argv);
void    swap_both(t_stack *stack_a, t_stack *stack_b);
void    push_to(t_stack *stack_a, t_stack *stack_b);
void    rotate(t_stack *stack);
void    rotate_both(t_stack *stack_a, t_stack *stack_b);
void    print_stack(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	push_to_second_stack(t_stack *stack_a, t_stack *stack_b);
int		count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int elem);
t_stack	*allocate_memory(int len);
t_stack	*ft_strsplit_to_int(char const *s);
size_t	str_calc(char const *s);
char	**ft_strsplitspaces(char const *s);
char	*ft_arrjoin(char **arr, int len);
int		validate(char *str);

#endif