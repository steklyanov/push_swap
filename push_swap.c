/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/22 15:53:37 by mmraz            ###   ########.fr       */
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
            if (validate(argv[index]))
            {
                //  Возможно нужно ft_strnew сделать внутри и после каждой операции делать ft_memdel;
                result = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]), str_calc(argv[index])));
                result = ft_strjoin(result, " ");
            }
            else
            {
                printf("error\n");
                return (0);
            }
            index++;
        }
        stack_a = ft_strsplit_to_int(result);
        if (ft_check_equal(stack_a))
        {
            stack_b = allocate_memory(stack_a->len);
            print_stack(stack_a, stack_b);
            swap_one(stack_a);
            print_stack(stack_a, stack_b);
        }
        else
        {
            printf("not equal\n");
        }

    }
    else
        ft_print_usage();
    return (0);
}