/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:43:32 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/02 15:00:22 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define BUF_SIZE 4

void    return_stack_string_2(int argc, char **argv)
{
    char *result;
    int index;
    char *tmp;
    t_stack *stack_a;
    t_stack *stack_b;

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
    if (ft_strlen(result) == 1 && result[0] == '\0')
        printf("Error\n");
    else
    {
        stack_a = ft_strsplit_to_int(result);
        if (ft_check_equal(stack_a))
        {
            stack_b = allocate_memory(stack_a->len);
            stack_b->len = 0;
            validate_operations(stack_a, stack_b);
        }
        else
            printf("Error\n");
    }
}

int main(int argc, char **argv)
{
    return_stack_string_2(argc, argv);
    return (0);
}


int    validate_operations(t_stack *stack_a, t_stack *stack_b)
{
    char *line;

	while (get_next_line(0, &line) > 0)
	{
        printf(" while gnl line = %s\n", line);
        if (!exec_operation(line, stack_a, stack_b))
        {
            printf("Error!");
            return (0);
        }
        print_stack(stack_a, stack_b);
	}
	return (1);
}

int    stack_operation(char *line)
{
    if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n") || !ft_strcmp(line, "ss\n") || !ft_strcmp(line, "pa\n") ||
    !ft_strcmp(line, "pb\n") || !ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n") ||
    !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n") || !ft_strcmp(line, "rrr\n"))
        return (1);
    return (0);
}

int    exec_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
    printf("%s", line);
    if (!ft_strcmp(line, "sa"))
        swap_one(stack_a, 1);
    else if (!ft_strcmp(line, "sb"))
        swap_one(stack_b, 1);
    else if (!ft_strcmp(line, "ss"))
        swap_both(stack_a, stack_b, 1);
    else if (!ft_strcmp(line, "pa"))
        push_to(stack_a, stack_b);
    else if (!ft_strcmp(line, "pb"))
        push_to(stack_b, stack_a);
    else if (!ft_strcmp(line, "ra"))
        rotate(stack_a, 1);
    else if (!ft_strcmp(line, "rb"))
        rotate(stack_b, 1);
    else if (!ft_strcmp(line, "rr"))
        reverse_rotate(stack_a, 1);
    else if (!ft_strcmp(line, "rra"))
        reverse_rotate(stack_a, 1);
    else if (!ft_strcmp(line, "rrb"))
        reverse_rotate(stack_b, 1);
    else if (!ft_strcmp(line, "rrr"))
        reverse_rotate_both(stack_a, stack_b, 1);
    else
        return (0);
    return (1);
}