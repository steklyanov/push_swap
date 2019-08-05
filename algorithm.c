/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:29:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/05 17:51:30 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_second_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = stack_a->len - 3;
	while (index-- > 0)
	{
		push_to(stack_b, stack_a);
		ft_print("pb\n", 1);
	}
}

int		choose_sort_three(t_stack *stack_a)
{
	if (stack_a->stack[0] < stack_a->stack[1] &&
	stack_a->stack[1] > stack_a->stack[2])
	{
		if (stack_a->stack[0] > stack_a->stack[2])
			return (1);
		else
			return (2);
	}
	else if (stack_a->stack[0] > stack_a->stack[1] &&
	stack_a->stack[1] > stack_a->stack[2])
		return (3);
	else if (stack_a->stack[0] > stack_a->stack[1] &&
	stack_a->stack[1] < stack_a->stack[2])
	{
		if (stack_a->stack[0] > stack_a->stack[2])
			return (4);
		else
			return (5);
	}
	return (0);
}

void	sort_three(t_stack *stack_a)
{
	int	result;

	result = choose_sort_three(stack_a);
	if (result < 4)
		sort_half(result, stack_a);
	else if (result == 4)
	{
		rotate(stack_a, 1);
		ft_print("ra\n", 1);
	}
	else if (result == 5)
	{
		swap_one(stack_a, 1);
		ft_print("sa\n", 1);
	}
}

void	sort_half(int result, t_stack *stack_a)
{
	if (result == 1)
	{
		reverse_rotate(stack_a, 1);
		ft_print("rra\n", 1);
	}
	else if (result == 2)
	{
		reverse_rotate(stack_a, 1);
		swap_one(stack_a, 1);
		ft_print("rra\n", 1);
		ft_print("sa\n", 1);
	}
	else if (result == 3)
	{
		swap_one(stack_a, 1);
		reverse_rotate(stack_a, 1);
		ft_print("sa\n", 1);
		ft_print("rra\n", 1);
	}
}

void	dealer(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	t_sol	tmp;
	t_sol	min_sol;
	int		min_index;

	tmp.len = 0;
	min_index = 0;
	while (stack_b->len > 0)
	{
		index = 0;
		min_sol.len = 100;
		while (index < stack_b->len)
		{
			tmp = count_moves_to_put(stack_a, stack_b, index);
			if (tmp.len < min_sol.len)
			{
				min_sol = tmp;
				min_index = index;
			}
			index++;
		}
		push_to_stack(min_index, &min_sol, stack_a, stack_b);
	}
	rotate_to_norme(stack_a);
}
