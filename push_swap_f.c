/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:50:21 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/19 16:19:26 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_isspace(char s)
{
    return (s == 32 || s == 10 || s == 9 || s == 12 ||
			s == 13 || s == 11);
}


void    print_stack(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    i = 0;
    printf("Stack A, len = %d\n", stack_a->len);
    while(i < stack_a->len)
    {
        printf("%d ", stack_a->stack[i]);
        i++;
    };
    i = 0;
    printf("\n");
    printf("Stack B, len = %d\n", stack_b->len);
    while(i < stack_b->len)
    {
        printf("%d ", stack_b->stack[i]);
        i++;
    };
}