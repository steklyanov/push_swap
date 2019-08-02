/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:18:21 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/02 16:19:05 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     check_sorting(t_stack *stack_a, t_stack *stack_b)
{
    int index;

    index = 0;
    if (stack_b->len != 0)
        return (1);
    while(index < stack_a->len - 2 && stack_a->stack[index] < stack_a->stack[index + 1])
        index++;
    return (stack_a->len - index);
}
