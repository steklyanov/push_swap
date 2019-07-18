/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:37:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/18 17:52:48 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_small(const char *str)
{
	int			i;
	int			isneg;
	long long	result;
	long long	tmp;

	i = 0;
	result = 0;
	isneg = 1;
	if (str[i] == '-')
		isneg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		tmp = result;
		result = result * 10 + (str[i] - 48);
		if (tmp > result)
			return (isneg == -1 ? 0 : -1);
		i++;
	}
	return (isneg * (int)result);
}
