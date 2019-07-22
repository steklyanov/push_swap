/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:29:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 19:41:51 by mmraz            ###   ########.fr       */
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

int sort_three(t_stack *stack_a)
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

// int count_moves_to_put(t_stack *stack_a, t_stack *stack_b)
// {
//     int counter;

//     counter = 0;
//     stack_a = stack_a;
//     stack_b = stack_b;
//     return (0);
// }