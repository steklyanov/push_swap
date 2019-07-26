/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenarios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:01:19 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/26 16:42:54 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_print(char *comma, int rep)
{
    while(rep--)
    {
        printf("%s", comma);
    }
}

void    scenario_1(t_stack *stack_a, t_stack *stack_b, int index)
{
    int repeat;
    int ra;

    ra = find_pos_in_a(stack_a, stack_b->stack[index]);
    repeat = (index < ra) ? index : ra;
    rotate_both(stack_a, stack_b, repeat);
    ft_print("rr",repeat);
    if (index < ra)
    {
        rotate(stack_a, ra - index);
        ft_print("ra", ra - index);
    }
    else
    {
        rotate(stack_a, index - ra);
        ft_print("rb", index - ra);
    }
}

// void    scenario_2(t_stack *stack_a, t_stack *stack_b, int index)
// {

// }

// void    scenario_3(t_stack *stack_a, t_stack *stack_b, int index)
// {

// }

// void    scenario_4(t_stack *stack_a, t_stack *stack_b, int index)
// {

// }
