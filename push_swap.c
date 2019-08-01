/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/01 21:42:22 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char    *result;
    t_stack *stack_a;
    t_stack *stack_b;

    if(argc > 1)
    {
        result = return_stack_string(argc, argv);
        if (ft_strlen(result) == 1 && result[0] == '\0')
            printf("Error\n");
        else
        {
            stack_a = ft_strsplit_to_int(result);
            if (ft_check_equal(stack_a))
            {
                stack_b = allocate_memory(stack_a->len);
                stack_b->len = 0;
                main_operations(stack_a, stack_b);
            }
            else
                printf("Error\n");
        }
        free(result);
    }
    else
        ft_print_usage();
    return (0);
}

void    main_operations(t_stack *stack_a, t_stack *stack_b)
{
    push_to_second_stack(stack_a, stack_b);
    sort_three(stack_a);
    dealer(stack_a, stack_b);
    print_stack(stack_a, stack_b);
}

char    *return_stack_string(int argc, char **argv)
{
    char *result;
    int index;
    // char *tmp;

    index  = 1;
    result = ft_strnew(0);
    while(argc > index)
    {
        if (validate(argv[index]))
        {
            //  Возможно нужно ft_strnew сделать внутри и после каждой операции делать ft_memdel;
            result = ft_strjoin(result, ft_arrjoin(ft_strsplitspaces(argv[index]), str_calc(argv[index])));
            result = ft_strjoin(result, " ");
            // result = tmp;
            // free(tmp);
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