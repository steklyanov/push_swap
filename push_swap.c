/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/18 18:41:49 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *result;
    int     *result2;
    int     index;

    if(argc > 1)
    {
        index  = 1;
        result = ft_strnew(1);
        while(argc > index)
        {
            result = ft_strjoin(result, " ");
            result = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]), str_calc(argv[index])));
            index++;
        }
        printf("%s\n", result);
        result2 = ft_strsplit_to_int(result);
        printf("%d\n", result2[0]);
        printf("%d\n", result2[1]);
        printf("%d\n", result2[2]);
    }
    return (0);
}