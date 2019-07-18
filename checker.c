/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:43:32 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/18 16:22:27 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *result;
    int     index;

    

    if(argc > 1)
    {
        index  = 1;
        result = ft_strnew(0);
        while(argc >= index)
        {
            result = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]),  str_calc(argv[index])));
        }
        printf("%s\n", result);
    }
    // if (!(result = (int *)malloc(sizeof(int *) * argc - 1)))
    // {
    //   		return (69);
    // }
    // while (index < argc)
    // {
    //     result[index - 1] = ft_atoi(argv[index]);
    //     index++;
    // }
    // printf("%s\n", argv[1]);
    // printf("%d\n", result[0]);
    // printf("%d\n", result[1]);
    // printf("%d\n", result[2]);

    // ft_strsplit(**argv);
    return (0);
}
