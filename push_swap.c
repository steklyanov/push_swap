/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/03 18:11:11 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	char	*result;
	t_stack *stack_a;

	if (argc > 1)
	{
		result = return_stack_string(argc, argv);
		if (ft_strlen(result) == 0)
			printf("Error\n");
		else
		{
			if (!(stack_a = ft_strsplit_to_int(result)))
				ft_printf("Error\n");
			else if (ft_check_equal(stack_a))
				main_operations(stack_a);
			else
				ft_printf("Error\n");
			(stack_a) ? free(stack_a->stack): ft_printf(""); 
			free(stack_a);
		}
		free(result);
	}
	return (0);
}

void	main_operations(t_stack *stack_a)
{
	t_stack *stack_b;
	
	stack_b = allocate_memory(stack_a->len);
	stack_b->len = 0;
	if (check_sorting(stack_a, stack_b) != 2)
	{
		push_to_second_stack(stack_a, stack_b);
		sort_three(stack_a);
		dealer(stack_a, stack_b);
	}
	free(stack_b->stack);
	free(stack_b);
}

static void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*return_stack_string(int argc, char **argv)
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
		free_str(tmp2);
	}
	free(tmp);
	return (result);
}
