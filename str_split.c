/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:21:54 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/09 16:59:31 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_wrds_cnt(char *str)
{
	int		index;
	int		result;

	index = 0;
	result = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			result++;
		while (s[index] && (s[index] != c))
			index++;
	}
	return (result);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

static void	free_str(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(*str);
}

int		**ft_strsplit(char *str)
{
	int	**result;
    char    
	int		index;
	int		j;
	int		z;

	index = 0;
	j = 0;
	z = 0;
	if (!str)
		return (69);
	if (!(result = (int **)malloc(sizeof(int *) * (get_wrds_cnt(str) + 1))))
		return (69);
	while (str[index])
	{
		while (str[index] == ' ')
			index++;
		j = index;
		while (str[index] && str[index] != ' ')
			index++;
		if (index > j)
			if (!(result[z++] = ft_strndup(str + j, index - j)))
				free_str(result);
	}
	result[z] = 0;
	return (result);
}