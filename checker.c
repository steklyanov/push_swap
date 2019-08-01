/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:43:32 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/01 20:28:28 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char    *return_stack_string_2(int argc, char **argv)
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
        }
        else
            printf("Error\n");
        validate_operations(argv, index, stack_a, stack_b);
    }
    
    return (result);
}

int main(int argc, char **argv)
{
    return_stack_string_2(argc, argv);
    return (0);
}

void    validate_operations(char **argv, int index, t_stack *stack_a, t_stack *stack_b)
{
    int     fd;
    char    *line;

    fd = open(argv[index], O_RDONLY);

    while (get_next_line(fd, &line))
    {
        if (stack_operation(line) != 0)
            exec_operation(line, stack_a, stack_b);
        else
        {
            ft_printf("Error\n");
            break;
        }
    }
}

int    stack_operation(char *line)
{
    if (line == "sa\n" || line == "sb\n" || line == "ss\n" || line == "pa\n" ||
    line == "pb\n" || line == "ra\n" || line == "rb\n" || line == "rr\n" ||
    line == "rra\n" || line == "rrb\n" || line == "rrr\n")
        return (1);
    return (0);
}

void    exec_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
    if (line == "sa\n")
        swap_one(stack_a, 1);
    else if (line == "sb\n")
        swap_one(stack_b, 1);
    else if (line == "ss\n")
        swap_both(stack_a, stack_b, 1);
    else if (line == "pa\n")
        push_one(stack_a, 1);
    else if (line == "pb\n")
        push_one(stack_b, 1);
    else if (line == "ra\n")
        rotate(stack_a, 1);
    else if (line == "rb\n")
        rotate(stack_b, 1);
    else if (line == "rr\n")
        reverse_rotate(stack_a, 1);
    else if (line == "rra\n")
        reverse_rotate(stack_b, 1);
    else if (line == "rrb\n")
    reverse_rotate(stack_b, 1);
    else if (line == "rrr\n")
    reverse_rotate_both(stack_a, stack_b, 1);
    return (0);
}