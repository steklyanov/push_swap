/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:43:32 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/01 18:08:16 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char *result;
    int index;
    char *tmp;

    index  = 1;
    result = ft_strnew(1);
    while(argc > index)
    {
        if (validate(argv[index]))
        {
            //  Возможно нужно ft_strnew сделать внутри и после каждой операции делать ft_memdel;
            tmp = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]), str_calc(argv[index])));
            tmp = ft_strjoin(tmp, " ");
            result = tmp;
            // free(tmp);
        }
        else
            break;
        index++;
    }
    if (is_stack_operation(argv[index]))
        validate_operations(**argv, index, result);
    return (0);
}

void    validate_operations(char **argv, int index, char *result)
{
    
}