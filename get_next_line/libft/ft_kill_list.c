/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 08:09:43 by mmraz             #+#    #+#             */
/*   Updated: 2018/12/06 08:10:14 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_kill_list(t_list *lst)
{
	while (lst)
	{
		free(lst->content);
		free(lst);
		lst = lst->next;
	}
}
