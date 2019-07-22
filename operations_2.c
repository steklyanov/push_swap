/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:04:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 18:15:58 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_stack *stack)
{
    int index;
    int tmp;

    index = stack->len - 1;
    tmp = stack->stack[index];
    while(index > 0)
    {
        stack->stack[index] = stack->stack[index - 1];
        index--;; 
    }
    stack->stack[index] = tmp;
}

void    reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}