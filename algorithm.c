/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:29:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/02 16:03:08 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_second_stack(t_stack *stack_a, t_stack *stack_b)
{
    int index;

    index = stack_a->len - 3;
    while(index-- > 0)
    {
        push_to(stack_b, stack_a);
        ft_print("pb\n", 1);
    }
}

int choose_sort_three(t_stack *stack_a)
{
    if (stack_a->stack[0] < stack_a->stack[1] && stack_a->stack[1] > stack_a->stack[2])
    {
        if (stack_a->stack[0] > stack_a->stack[2])
            return(1);
        else
            return (2);
    }
    else if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[1] > stack_a->stack[2])
        return (3);
    else if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[1] < stack_a->stack[2])
    {
        if (stack_a->stack[0] > stack_a->stack[2])
            return(4);
        else
            return (5);
    }
    return (0); 
}
 
void    sort_three(t_stack *stack_a)
{
    int result;

    result = choose_sort_three(stack_a);
    if (result == 1)
    {
        reverse_rotate(stack_a, 1);
        ft_print("rra\n", 1);
    }
    else if (result == 2)
    {
        swap_one(stack_a, 1);
        rotate(stack_a, 1);
        ft_print("sa\n", 1);
        ft_print("ra\n", 1);
    }
    else if (result == 3)
    {
        swap_one(stack_a, 1);
        reverse_rotate(stack_a, 1);
        ft_print("sa\n", 1);
        ft_print("rra\n", 1);
    }
    else if (result == 4)
    {
        rotate(stack_a, 1);
        ft_print("ra\n", 1);
    }
    else if (result == 5)
    {
        swap_one(stack_a, 1);
        ft_print("sa\n", 1);
    }
}

void    dealer(t_stack *stack_a, t_stack *stack_b)
{
    int index;
    t_solution tmp;
    t_solution  min_sol;
    int min_index;

    tmp.len = 0;
    min_index = 0;
    while (stack_b->len > 0)
    {
        index = 0;
        min_sol.len = 100;
        while(index < stack_b->len)
        {
            tmp = count_moves_to_put(stack_a, stack_b, index);
            if (tmp.len < min_sol.len)
            {
                min_sol = tmp;
                min_index = index;
            }
            index++;
        }
        push_to_stack(min_index, &min_sol, stack_a, stack_b);
    }
    rotate_to_norme(stack_a);
}

void    rotate_to_norme(t_stack *stack_a)
{
    int index;

    index = 0;
    while (index < stack_a->len)
    {
        if (stack_a->stack[index] > stack_a->stack[index + 1])
            break;
        index++;
    }
    index++;
    if (stack_a->len / index > 0.5)
    {
        reverse_rotate(stack_a, stack_a->len - index);
        ft_print("rra\n", stack_a->len - index);
    }
    else
    {
        rotate(stack_a, index);
        ft_print("ra\n", index);
    }
    
}

void     push_to_stack(int index, t_solution *min_sol, t_stack *stack_a, t_stack *stack_b)
{
    if (min_sol->sol_nmbr == 1)
        scenario_1(stack_a, stack_b, index);
    else if (min_sol->sol_nmbr == 2)
        scenario_2(stack_a, stack_b, index);
    else if (min_sol->sol_nmbr == 3)
        scenario_3(stack_a, stack_b, index);
    else if (min_sol->sol_nmbr == 4)
        scenario_4(stack_a, stack_b, index);
}

int find_pos_in_a(t_stack *stack_a, int elem)
{
    int index;

    index = 0;
    while (index < stack_a->len)
    {
        if (stack_a->stack[index] > stack_a->stack[index + 1])
        {
            if (elem > stack_a->stack[index] || elem < stack_a->stack[index + 1])
                return (index + 1);
        }
        else if (elem > stack_a->stack[index] && elem < stack_a->stack[index + 1])
            return (index + 1);
        index++;
    }
    return (0);
}

t_solution count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int index)
{
    t_solution sol;
    int ra;
    int rra;
    int rb;
    int rrb;

    ra = find_pos_in_a(stack_a, stack_b->stack[index]);
    rb = index;
    rra = stack_a->len - ra;
    rrb = stack_b->len - index;
    sol.res_1 = (ra > rb) ? ra : rb; // ra and rb
    sol.res_2 = (rra > rrb) ? rra : rrb; // rra and rrb
    sol.res_3 = rra + rb; // rra and rb
    sol.res_4 = rrb + ra; // ra and rrb
    ft_fill_min(&sol);
    return (sol);
}

void      ft_fill_min(t_solution *sol)
{
    if (sol->res_1 < sol->res_2 && sol->res_1 < sol->res_3 && sol->res_1 < sol->res_4)
    {
        sol->len = sol->res_1;
        sol->sol_nmbr = 1;
    }
    else if (sol->res_2 < sol->res_3 && sol->res_2 < sol->res_4)
    {
        sol->len = sol->res_2;
        sol->sol_nmbr = 2;
    }
    else if (sol->res_3 < sol->res_4)
    {
        sol->len = sol->res_3;
        sol->sol_nmbr = 3;
    }
    else
    {
        sol->len = sol->res_4;
        sol->sol_nmbr = 4;
    }
}