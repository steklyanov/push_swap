/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:29:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/23 14:17:45 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_second_stack(t_stack *stack_a, t_stack *stack_b)
{
    int index;

    index = stack_a->len - 3;
    while(index-- > 0)
    {
        push_to(stack_b, stack_a);
    }
}

int choose_sort_three(t_stack *stack_a)
{
    // if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[1] > stack_a->stack[2])
    if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[1] < stack_a->stack[2])
    {
        if (stack_a->stack[2] < stack_a->stack[0])
        {
            // rb sa
            return(1);
        }
        else
        {
            // rra
            return (2);
        }
    }
    else if (stack_a->stack[0] < stack_a->stack[1] && stack_a->stack[1] < stack_a->stack[2])
    {
        // rra rra 
        return (3);
    }
    else if (stack_a->stack[0] < stack_a->stack[1] && stack_a->stack[1] > stack_a->stack[2])
    {
        if (stack_a->stack[0] > stack_a->stack[2])
        {
            // sa
            return(4);
        }
        else
        {
            // ra
            return (5);
        }
    }
    return (0); 
}

void    sort_three(t_stack *stack_a)
{
    int result;

    result = choose_sort_three(stack_a);
    if (result == 1)
    {
        rotate(stack_a);
        swap_one(stack_a);
    }
    else if (result == 2)
        reverse_rotate(stack_a);
    else if (result == 3)
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_a);
    }
    else if (result == 4)
        swap_one(stack_a);
    else if (result == 5)
        rotate(stack_a);
}

int count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int elem)
{
    int counter;

    counter = 0;
    stack_a = stack_a;
    stack_b = stack_b;
    return (0);
}