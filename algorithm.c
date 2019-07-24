/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:29:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/07/24 13:03:04 by mmraz            ###   ########.fr       */
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
    printf("%d stack_a->stack[0]\n", stack_a->stack[0]);
    printf("%d stack_a->stack[1]\n", stack_a->stack[1]);
    printf("%d stack_a->stack[2]\n", stack_a->stack[2]);
    // if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[1] > stack_a->stack[2])
    if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[1] < stack_a->stack[2])
    {
        if (stack_a->stack[2] < stack_a->stack[0])
        {
            // rb sa rrb
            return(1);
        }
        else
        {
            // rra
            return (2);
        }
    }
    else if (stack_a->stack[0] < stack_a->stack[1] && stack_a->stack[1] < stack_a->stack[2])
    {
        // rra rra 
        return (3);
    }
    else if (stack_a->stack[0] < stack_a->stack[1] && stack_a->stack[1] > stack_a->stack[2])
    {
        if (stack_a->stack[0] > stack_a->stack[2])
        {
            // sa
            return(4);
        }
        else
        {
            // ra
            return (5);
        }
    }
    return (0); 
}

//  TODO: check all possible varables!!!
void    sort_three(t_stack *stack_a)
{
    int result;

    result = choose_sort_three(stack_a);
    printf("result %d\n", result);
    if (result == 1)
    {
        rotate(stack_a);
        swap_one(stack_a);
        reverse_rotate(stack_a);
    }
    else if (result == 2)
        reverse_rotate(stack_a);
    else if (result == 3)
    {
        swap_one(stack_a);
        reverse_rotate(stack_a);
    }
    else if (result == 4)
        swap_one(stack_a);
    else if (result == 5)
        rotate(stack_a);
}

// t_moves *create_list()
// {
//     t_moves *moves;

//     if (!(moves = (t_moves*)malloc(sizeof(t_moves))))
// 		return (NULL);
//     moves->next = NULL;
//     return (moves);
// }

// t_moves *dealer(t_stack *stack_a, t_stack *stack_b)
// {
//     t_moves *moves;

//     moves = create_list();
//     while (stack_b->len > 0)
//     {
//         push_to_stack
//     }
// }

void    *dealer(t_stack *stack_a, t_stack *stack_b)
{
    int index;
    int min;
    int tmp;
    int min_index;

    tmp = 0;
    min_index = 0;
    while (stack_b->len > 0)
    {
        index = 0;
        min = 100;
        while(index < stack_b->len)
        {
            tmp = count_moves_to_put(stack_a, stack_b, index);
            if (tmp < min)
            {
                min = tmp;
                min_index = index;
            }
        }
        // push_to_stack(min_index);
    }
}

// int     push_to_stack(int index);
// {
// Эта функция изменяет стек и печатает в консоль


// }

int count_moves_to_put(t_stack *stack_a, t_stack *stack_b, int elem)
{
    // Эта функция просто считает количество необходимых операций
    
    //  Дается номер элемента из стека Б и для него узнается минимальное
    // количество операциий для помещения в нужную часть 
    // стека А через верх или через низ
    // 1. Просчпет как быстрее через верх или низ поднять элемент
    // 2. Просчет нужной позиции в стеке
    // 3. примерка через верх и низ  собьединением второго стека:
    //  Один вверх другой вниз 
    //  Оба вверх 
    // Оба вниз
    // Один вниз другой вверх
//     int counter;


}