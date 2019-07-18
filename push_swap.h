/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:01:13 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/18 16:36:42 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include "libft/libft.h"

int     ft_isspace(char s);
int		ft_isdigit(int c);
size_t	str_calc(char const *s);
char	**ft_strsplitspaces(char const *s);
char	*ft_arrjoin(char **arr, int len);


#endif