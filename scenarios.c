/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenarios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:01:19 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/24 20:04:35 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    scenario_1(t_stack *stack_a, t_stack *stack_b, int index)
{
    int repeat;
    int ra;

    ra = find_pos_in_a(stack_a, stack_b->stack[index]);
    repeat = (index < ra) ? index : ra;
    while(repeat--)
    {
        rotate_both(stack_a, stack_b);
        printf("rr");
    }
    if (index < ra)
    {
        while (ra - index)
        {
            rotate(stack_a);
            printf("ra");
        }
        
    }
    else
    {
        while (ra - index)
        {
            rotate(stack_a);
            printf("ra");
        }
    }
    

    

}

void    scenario_2(t_stack *stack_a, t_stack *stack_b, int index)
{

}

void    scenario_3(t_stack *stack_a, t_stack *stack_b, int index)
{

}

void    scenario_4(t_stack *stack_a, t_stack *stack_b, int index)
{

}
