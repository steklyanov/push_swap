/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:57:57 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/05 14:26:24 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		validate(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!(ft_isdigit(str[index]) || ft_isspace(str[index]) ||
			((str[index] == '-' || str[index] == '+')
			&& ft_isdigit(str[index + 1]) && (index == 0 ||
			ft_isspace(str[index - 1])))))
			return (0);
		index++;
	}
	return (1);
}

void	free_string(char **str)
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

int		ft_check_equal(t_stack *stack)
{
	int index;
	int loop;

	index = 0;
	while (index < stack->len)
	{
		loop = 0;
		while (loop < index)
		{
			if (stack->stack[index] == stack->stack[loop++])
				return (0);
		}
		index++;
	}
	return (1);
}
