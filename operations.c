/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:46:34 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 16:02:52 by mmraz            ###   ########.fr       */
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