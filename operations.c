/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:46:34 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 18:15:56 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_one(t_stack *stack_a)
{
    int tmp_a;

    if (stack_a->stack[0] && stack_a->stack[1])
    {
        tmp_a = stack_a->stack[0];
	    stack_a->stack[0] = stack_a->stack[1];
	    stack_a->stack[1] = tmp_a;
    }
}

void    swap_both(t_stack *stack_a, t_stack *stack_b)
{
    swap_one(stack_a);
    swap_one(stack_b);
}

void    push_to(t_stack *stack_a, t_stack *stack_b)
{
        int tmp_a;
        int index;

        index = 0;
        if (stack_b->len)
        {
            tmp_a = stack_b->stack[0];
            while(index <= stack_b->len - 2)
            {
                stack_b->stack[index] = stack_b->stack[index + 1];
                index++; 
            }
            index = stack_a->len;
            while(index > 0)
            {
                stack_a->stack[index] = stack_a->stack[index - 1];
                index--;; 
            }
            stack_a->stack[index] = tmp_a;
            stack_a->len++;
            stack_b->len--;
            // free tmp;
        }
}

void    rotate(t_stack *stack)
{
    int tmp;
    int index;

    index  = 0;
    tmp = stack->stack[0];
    while(index <= stack->len - 2)
    {
        stack->stack[index] = stack->stack[index + 1];
        index++; 
    }
    stack->stack[index] = tmp;
}

void    rotate_both(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}