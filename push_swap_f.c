/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:50:21 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/03 12:52:10 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	printf("Stack A, len = %d\n", stack_a->len);
	while (i < stack_a->len)
	{
		printf("%d ", stack_a->stack[i]);
		i++;
	}
	i = 0;
	printf("\n");
	printf("Stack B, len = %d\n", stack_b->len);
	if (stack_b->len > 0)
	{
		while (i < stack_b->len)
		{
			printf("%d ", stack_b->stack[i]);
			i++;
		}
		printf("\n");
	}
}
