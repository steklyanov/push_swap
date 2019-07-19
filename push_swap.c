/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/19 16:22:07 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char    *result;
    t_stack *stack_a;
    t_stack *stack_b;
    int     index;

    if(argc > 1)
    {
        index  = 1;
        result = ft_strnew(1);
        while(argc > index)
        {
            if (!validate(argv[index]))
            {
                result = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]), str_calc(argv[index])));
                result = ft_strjoin(result, " ");
                stack_a = ft_strsplit_to_int(result);
                stack_b = allocate_memory(stack_a->len);
            }
            else
            {
                printf("error\n");
                raise_error(1);
            }
            index++;
        }
        print_stack(stack_a, stack_b);
    }
    return (0);
}