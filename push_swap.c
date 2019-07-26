/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/26 17:12:26 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char    *result;
    t_stack *stack_a;
    t_stack *stack_b;
    int     index;
    char    *tmp;

    if(argc > 1)
    {
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
            stack_b->len = 0;
            print_stack(stack_a, stack_b);
            push_to_second_stack(stack_a, stack_b);
            print_stack(stack_a, stack_b);
            sort_three(stack_a);
            print_stack(stack_a, stack_b);
            // count_moves_to_put(stack_a, stack_b, 3);
            dealer(stack_a, stack_b);
            // printf("result = %d", );
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

char        *concat_all(int argc, char **argv)
{
    char    *result;
    int     index;
    char    *tmp;

    index  = 1;
    result = ft_strnew(1);
    while(argc > index)
    {
        if (validate(argv[index]))
        {
            tmp = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]), str_calc(argv[index])));
            free(result);
            result = tmp;
            free(tmp);
        }
        else
        {
            printf("error\n");
            return (0);
        }
        index++;
    }
    return (result);
}