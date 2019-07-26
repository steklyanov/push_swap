/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:04:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/26 18:23:09 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_stack *stack, int rep)
{
    int index;
    int tmp;

    index = stack->len - 1;
    tmp = stack->stack[index];
    if (rep)
    {
        while(index > 0)
        {
            stack->stack[index] = stack->stack[index - 1];
            index--;; 
        }
        stack->stack[index] = tmp;
        reverse_rotate(stack, rep - 1);
    }

}

void    reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, int rep)
{
    reverse_rotate(stack_a, rep);
    reverse_rotate(stack_b, rep);
}