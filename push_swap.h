/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:01:13 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/26 18:23:07 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack t_stack;
typedef struct s_solution t_solution;

struct		s_stack
{
	int		len;
	int		*stack;
};

struct		s_solution 
{
	int		sol_nmbr;
	int		len;
	int		res_1;
    int		res_2;
    int		res_3;
    int		res_4;	
};


int		ft_atoi_small(const char *str);
int     ft_isspace(char s);
int		ft_isdigit(int c);
void	ft_print_usage();
int		ft_check_equal(t_stack *stack);
void    sort_three(t_stack *stack_a);
void    dealer(t_stack *stack_a, t_stack *stack_b);
t_solution		count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int elem);
void      ft_fill_min(t_solution *sol);
int		choose_sort_three(t_stack *stack_a);
void    swap_one(t_stack *stack_a, int rep);
char	*concat_all(int argc, char **argv);
int find_pos_in_a(t_stack *stack_a, int elem);
void    swap_both(t_stack *stack_a, t_stack *stack_b, int rep);
void    push_to(t_stack *stack_a, t_stack *stack_b);
void    push_to_stack(int index, t_solution *min_sol, t_stack *stack_a, t_stack *stack_b);
void    rotate(t_stack *stack, int rep);
void    rotate_both(t_stack *stack_a, t_stack *stack_b, int rep);
void    print_stack(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack, int rep);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, int rep);
void	push_to_second_stack(t_stack *stack_a, t_stack *stack_b);
void    ft_print(char *comma, int rep);
void	scenario_1(t_stack *stack_a, t_stack *stack_b, int index);
void	scenario_2(t_stack *stack_a, t_stack *stack_b, int index);
void	scenario_3(t_stack *stack_a, t_stack *stack_b, int index);
void	scenario_4(t_stack *stack_a, t_stack *stack_b, int index);
// int		count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int elem);
t_stack	*allocate_memory(int len);
t_stack	*ft_strsplit_to_int(char const *s);
size_t	str_calc(char const *s);
char	**ft_strsplitspaces(char const *s);
char	*ft_arrjoin(char **arr, int len);
int		validate(char *str);

#endif