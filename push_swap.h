/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:01:13 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 16:04:14 by mmraz            ###   ########.fr       */
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
void    swap_one(t_stack *stack_a);
void    swap_both(t_stack *stack_a, t_stack *stack_b);
void    push_from(t_stack *stack_a);
void    print_stack(t_stack *stack_a, t_stack *stack_b);
t_stack	*allocate_memory(int len);
t_stack	*ft_strsplit_to_int(char const *s);
size_t	str_calc(char const *s);
char	**ft_strsplitspaces(char const *s);
char	*ft_arrjoin(char **arr, int len);
int		validate(char *str);

#endif