/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenarios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:01:19 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/31 15:00:26 by mmraz            ###   ########.fr       */
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

// RA and RB
void    scenario_1(t_stack *stack_a, t_stack *stack_b, int index)
{
    int repeat;
    int ra;

    ra = find_pos_in_a(stack_a, stack_b->stack[index]);
    printf("%d\n", ra);
    printf("%d\n", index);
    repeat = (index < ra) ? index : ra;
    printf("%d", repeat);
    printf("__________scenario 1\n");
    print_stack(stack_a, stack_b);
    printf("rotate both\n");
    rotate_both(stack_a, stack_b, repeat);
    print_stack(stack_a, stack_b);
    ft_print("rr\n",repeat);
    if (index < ra)
    {
        rotate(stack_a, ra - index);
        ft_print("ra\n", ra - index);
    }
    else if (ra < index)
    {
        rotate(stack_b, index - ra);
        ft_print("rb\n", index - ra);
    }
    push_to(stack_a, stack_b);
    print_stack(stack_a, stack_b);
}

// RES2 RRA and RRB
void    scenario_2(t_stack *stack_a, t_stack *stack_b, int index)
{
    int repeat;
    int rra;
    int rrb;

    rra = stack_a->len - find_pos_in_a(stack_a, stack_b->stack[index]);
    rrb = stack_b->len - index;
    printf("rra = %d\n", rra);
    printf("rrb = %d\n", rrb);
    printf("scenario 2\n");
    print_stack(stack_a, stack_b);
    repeat = (rrb < rra) ? rrb : rra;
    reverse_rotate_both(stack_a, stack_b, repeat);
    ft_print("rrr\n",repeat);
    printf("%d\n", rra);
    printf("%d\n", rrb);
    if (rrb < rra)
    {
        reverse_rotate(stack_a, rra - rrb);
        ft_print("rra\n", rra - rrb);
    }
    else if (rrb > rra)
    {
        reverse_rotate(stack_b, rrb - rra);
        ft_print("rrb\n", rrb - rra);
    }
    push_to(stack_a, stack_b);
    print_stack(stack_a, stack_b);
}

// res3 RRA and RB
void    scenario_3(t_stack *stack_a, t_stack *stack_b, int index)
{
    int rra;

    rra = stack_a->len - find_pos_in_a(stack_a, stack_b->stack[index]);
    
    printf("rra = %d", rra);
    printf("index = %d", index);
    printf("_________SCENARIO 3\n");
    print_stack(stack_a, stack_b);
    printf("reverse rotate\n");
    reverse_rotate(stack_a, rra);
    print_stack(stack_a, stack_b);
    printf("rra = %d\n", rra);
    ft_print("rra\n", rra);
    printf("rotate\n");
    rotate(stack_b, index);
    print_stack(stack_a, stack_b);
    printf("index = %d\n", index);
    ft_print("rb\n", index);
    printf("push\n");
    push_to(stack_a, stack_b);
    print_stack(stack_a, stack_b);
    ft_print("pa\n", 1);
}

// RA and RRB
void    scenario_4(t_stack *stack_a, t_stack *stack_b, int index)
{
    int ra;
    int rrb;

    rrb = stack_b->len - index;
    ra = find_pos_in_a(stack_a, stack_b->stack[index]);
    printf("rrb = %d\n", rrb);
    printf("index = %d\n", index);
    printf("___________scenario 4\n");
    print_stack(stack_a, stack_b);
    printf("rotate a\n");
    rotate(stack_a, ra);
    print_stack(stack_a, stack_b);
    ft_print("ra\n", ra);
    printf("rev rotate b\n");
    reverse_rotate(stack_b, rrb);
    print_stack(stack_a, stack_b);
    ft_print("rrb\n", rrb);
    printf("push\n");
    push_to(stack_a, stack_b);
    print_stack(stack_a, stack_b);
}

