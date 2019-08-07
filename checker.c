/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:43:32 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/07 17:21:57 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*return_stack_string_2(int argc, char **argv)
{
	char	*result;
	int		index;
	char	*tmp;
	char	**tmp2;

	index = 0;
	tmp = ft_arrjoin(&argv[1], argc - 1);
	result = ft_strnew(0);
	if (validate(tmp))
	{
		tmp2 = ft_strsplitspaces(tmp);
		while (tmp2[index++])
			;
		free(result);
		result = ft_arrjoin(tmp2, index - 1);
		free_string(tmp2);
	}
	free(tmp);
	return (result);
}

int		main(int argc, char **argv)
{
	char	*result;
	t_stack	*stack_a;

	if (argc > 1)
	{
		result = return_stack_string_2(argc, argv);
		if (ft_strlen(result) == 0 && result[0] == '\0')
			ft_printf("Error\n");
		else
		{
			stack_a = ft_strsplit_to_int(result);
			if (stack_a->len == 0)
				ft_printf("Error\n");
			else if (ft_check_equal(stack_a))
			{
				sort_stack(stack_a);
			}
			else
				ft_printf("Error\n");
			free(stack_a->stack);
			free(stack_a);
		}
		free(result);
	}
	return (0);
}

void	sort_stack(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = allocate_memory(stack_a->len);
	stack_b->len = 0;
	if (validate_operations(stack_a, stack_b))
		check_sorting(stack_a, stack_b) == 1 ?
		ft_printf("OK\n") : ft_printf("KO\n");
	free(stack_b->stack);
	free(stack_b);
}

int		validate_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		index;

	index = 0;
	while (get_next_line(0, &line) > 0)
	{
		index = 1;
		if (!exec_operation(line, stack_a, stack_b))
		{
			ft_printf("Error\n");
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int		exec_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sa"))
		swap_one(stack_a, 1);
	else if (!ft_strcmp(line, "sb"))
		swap_one(stack_b, 1);
	else if (!ft_strcmp(line, "ss"))
		swap_both(stack_a, stack_b, 1);
	else if (!ft_strcmp(line, "pa"))
		push_to(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		push_to(stack_b, stack_a);
	else if (!ft_strcmp(line, "ra"))
		rotate(stack_a, 1);
	else if (!ft_strcmp(line, "rb"))
		rotate(stack_b, 1);
	else if (!ft_strcmp(line, "rr"))
		rotate_both(stack_a, stack_b, 1);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(stack_a, 1);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(stack_b, 1);
	else if (!ft_strcmp(line, "rrr"))
		reverse_rotate_both(stack_a, stack_b, 1);
	else
		return (0);
	return (1);
}
