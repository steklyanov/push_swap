/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenarios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:01:19 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/05 15:17:04 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(char *comma, int rep)
{
	while (rep--)
	{
		ft_printf("%s", comma);
	}
}

void	scenario_1(t_stack *stack_a, t_stack *stack_b, int index)
{
	int repeat;
	int ra;

	ra = find_pos_in_a(stack_a, stack_b->stack[index]);
	repeat = (index < ra) ? index : ra;
	rotate_both(stack_a, stack_b, repeat);
	ft_print("rr\n", repeat);
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
	ft_print("pa\n", 1);
}

void	scenario_2(t_stack *stack_a, t_stack *stack_b, int index)
{
	int repeat;
	int rra;
	int rrb;

	rra = stack_a->len - find_pos_in_a(stack_a, stack_b->stack[index]);
	rrb = stack_b->len - index;
	repeat = (rrb < rra) ? rrb : rra;
	reverse_rotate_both(stack_a, stack_b, repeat);
	ft_print("rrr\n", repeat);
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
	ft_print("pa\n", 1);
}

void	scenario_3(t_stack *stack_a, t_stack *stack_b, int index)
{
	int rra;

	rra = stack_a->len - find_pos_in_a(stack_a, stack_b->stack[index]);
	reverse_rotate(stack_a, rra);
	ft_print("rra\n", rra);
	rotate(stack_b, index);
	ft_print("rb\n", index);
	push_to(stack_a, stack_b);
	ft_print("pa\n", 1);
}

void	scenario_4(t_stack *stack_a, t_stack *stack_b, int index)
{
	int ra;
	int rrb;

	rrb = stack_b->len - index;
	ra = find_pos_in_a(stack_a, stack_b->stack[index]);
	rotate(stack_a, ra);
	ft_print("ra\n", ra);
	reverse_rotate(stack_b, rrb);
	ft_print("rrb\n", rrb);
	push_to(stack_a, stack_b);
	ft_print("pa\n", 1);
}
