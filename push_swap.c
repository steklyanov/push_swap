/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:41:47 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/02 19:03:59 by mmraz            ###   ########.fr       */
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
            if (!stack_a)
                return (0);
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
    if (check_sorting(stack_a, stack_b) != 2)
    {
        push_to_second_stack(stack_a, stack_b);
        sort_three(stack_a);
        dealer(stack_a, stack_b);
    }

}

char    *return_stack_string(int argc, char **argv)
{
    char *result;
    int index;
    char **tmp;
    char *tmp2;
    char *tmp3;

    index  = 1;
    tmp2 = ft_strnew(0);
    while(argc > index)
    {
        if (validate(argv[index]))
        {
            //  Возможно нужно ft_strnew сделать внутри и после каждой операции делать ft_memdel;
            tmp = ft_strsplitspaces(argv[index]);
            tmp3 = ft_arrjoin(tmp, str_calc(argv[index]));
            result = ft_strjoin(tmp2, tmp3);
            free(tmp2);
            free(tmp3);
            tmp2 = ft_strjoin(result, " ");
            free(result);
            free(tmp);
        }
        else
        {
            printf("error\n");
            return (0);
        }
        index++;
    }
    return (tmp2);
}
