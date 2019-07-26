/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:29:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/26 18:37:51 by mmraz            ###   ########.fr       */
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
    printf("result %d\n", result);
    if (result == 1)
        reverse_rotate(stack_a, 1);
    else if (result == 2)
    {
        swap_one(stack_a, 1);
        rotate(stack_a, 1);
    }

    else if (result == 3)
    {
        swap_one(stack_a, 1);
        reverse_rotate(stack_a, 1);
    }
    else if (result == 4)
        rotate(stack_a, 1);
    else if (result == 5)
        swap_one(stack_a, 1);
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
}

void     push_to_stack(int index, t_solution *min_sol, t_stack *stack_a, t_stack *stack_b)
{
    printf("______PUSH TO STACK_______\n");
    printf("min sol = %d\n", min_sol->sol_nmbr);
    printf("index = %d\n", index);
    if (min_sol->sol_nmbr == 1)
        scenario_1(stack_a, stack_b, index);
    else if (min_sol->sol_nmbr == 2)
        scenario_2(stack_a, stack_b, index);
    else if (min_sol->sol_nmbr == 3)
        scenario_3(stack_a, stack_b, index);
    else if (min_sol->sol_nmbr == 4)
        scenario_4(stack_a, stack_b, index);
    stack_b->len--;
    stack_a->len++;
}

int find_pos_in_a(t_stack *stack_a, int elem)
{
    int index;

    index = 0;
    while (index < stack_a->len)
    {
        if (stack_a->stack[index] > elem)
            return (index);
        index++;
    }
    return (index);
}

t_solution count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int index)
{
    t_solution sol;
    int ra;
    printf("____________ COUNT MOVES TO PUTIN VV____________");
    printf("index - %d   number - %d\n", index, stack_b->stack[index]);
    printf("position looking for = %d\n", find_pos_in_a(stack_a, stack_b->stack[index]));
    ra = find_pos_in_a(stack_a, stack_b->stack[index]);

    printf("ra = %d\n", ra);
    printf("rra = %d\n", (stack_a->len - ra));
    printf("rb = %d\n", index);
    printf("rrb = %d\n", (stack_b->len - index));

    sol.res_1 = (index > ra) ? index + ra : 2 * ra; // ra and rb
    sol.res_2 = ((stack_b->len - index) > (stack_a->len - ra)) ? (stack_b->len - index) + (stack_a->len - ra): 2 * (stack_a->len - ra) - (stack_b->len - index); // rra and rrb
    sol.res_3 = index + 2 * (stack_a->len - ra); // rra and rb
    sol.res_4 = (stack_b->len - index) + 2 * ra; // ra and rrb

    printf("res1 = %d\n", sol.res_1);
    printf("res2 = %d\n", sol.res_2);
    printf("res3 = %d\n", sol.res_3);
    printf("res4 = %d\n", sol.res_4);
    ft_fill_min(&sol);
    printf("sol nmbr = %d\n", sol.sol_nmbr);
    printf("sol len = %d\n", sol.len);
// НЕ уверен, что она отрабатывает корректно!!
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