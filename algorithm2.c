/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:22:43 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/05 14:36:54 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_norme(t_stack *stack_a)
{
	int index;

	index = 0;
	while (index < stack_a->len)
	{
		if (stack_a->stack[index] > stack_a->stack[index + 1])
			break ;
		index++;
	}
	index++;
	if (stack_a->len == index - 1)
		;
	else if (stack_a->len / index > 0.5)
	{
		reverse_rotate(stack_a, stack_a->len - index);
		ft_print("rra\n", stack_a->len - index);
	}
	else
	{
		rotate(stack_a, index);
		ft_print("ra\n", index);
	}
}

void	push_to_stack(int index, t_sol *min, t_stack *stack_a, t_stack *stack_b)
{
	if (min->sol_nmbr == 1)
		scenario_1(stack_a, stack_b, index);
	else if (min->sol_nmbr == 2)
		scenario_2(stack_a, stack_b, index);
	else if (min->sol_nmbr == 3)
		scenario_3(stack_a, stack_b, index);
	else if (min->sol_nmbr == 4)
		scenario_4(stack_a, stack_b, index);
}

int		find_pos_in_a(t_stack *stack_a, int elem)
{
	int	index;

	index = 0;
	while (index < stack_a->len)
	{
		if (stack_a->stack[index] > stack_a->stack[index + 1])
		{
			if (elem > stack_a->stack[index] ||
			elem < stack_a->stack[index + 1])
				return (index + 1);
		}
		else if (elem > stack_a->stack[index] &&
		elem < stack_a->stack[index + 1])
			return (index + 1);
		index++;
	}
	return (0);
}

t_sol	count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int index)
{
	t_sol	sol;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;

	ra = find_pos_in_a(stack_a, stack_b->stack[index]);
	rb = index;
	rra = stack_a->len - ra;
	rrb = stack_b->len - index;
	sol.res_1 = (ra > rb) ? ra : rb;
	sol.res_2 = (rra > rrb) ? rra : rrb;
	sol.res_3 = rra + rb;
	sol.res_4 = rrb + ra;
	ft_fill_min(&sol);
	return (sol);
}

void	ft_fill_min(t_sol *sol)
{
	if (sol->res_1 < sol->res_2 && sol->res_1 < sol->res_3 &&
	sol->res_1 < sol->res_4)
	{
		sol->len = sol->res_1;
		sol->sol_nmbr = 1;
	}
	else if (sol->res_2 < sol->res_3 && sol->res_2 < sol->res_4)
	{
		sol->len = sol->res_2;
		sol->sol_nmbr = 2;
	}
	else if (sol->res_3 < sol->res_4)
	{
		sol->len = sol->res_3;
		sol->sol_nmbr = 3;
	}
	else
	{
		sol->len = sol->res_4;
		sol->sol_nmbr = 4;
	}
}
