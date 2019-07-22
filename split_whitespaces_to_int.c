/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespaces_to_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:55:14 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 18:15:35 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static int	get_wrds_cnt(char const *s)
{
	int		index;
	int		result;

	index = 0;
	result = 0;
	while (s[index])
	{
		while (s[index] == ' ')
			index++;
		if (s[index])
			result++;
		while (s[index] && (s[index] != ' '))
			index++;
	}
	return (result);
}

t_stack	    	*ft_strsplit_to_int(char const *s)
{
	t_stack	*result;
	int		index;
	int		z;
	int		len;

	index = 0;
	z = 0;
	if (!s)
		return (NULL);
	len = get_wrds_cnt(s);
	result = allocate_memory(len);
	while (s[index])
	{
		if (s[index] == ' ')
			index++;
        result->stack[z++] = ft_atoi_small(&s[index]);
		while (s[index] && s[index] != ' ')
			index++;
	}
	return (result);
}

t_stack		*allocate_memory(int len)
{
	t_stack	*result;

	if (!(result = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(result->stack = (int *)malloc(sizeof(int *) * len)))
		return (NULL);
	result->len = len;
	return (result);
}