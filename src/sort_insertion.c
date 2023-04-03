/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:04:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/03 22:32:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    ft_is_elem_of_chunk(uint32_t num, t_chunk *chunk)
{
    return (num >= chunk->min && num <= chunk->max);
}

uint32_t    ft_count_rotate_top(uint32_t pos, t_stack *stack)
{
    if (pos > (stack->size / 2))
        return (stack->size - pos + 1);
    else
        return (pos);
}

uint32_t    ft_count_rotate_bottom(uint32_t pos, t_stack *stack)
{
    if (pos > (stack->size / 2))
        return (stack->size - pos);
    else
        return (pos + 1);
}

void    ft_rotate_and_push(t_stacks *stacks, uint32_t num, t_stack *dst, t_stack *src)
{
    uint32_t    higher;
    uint32_t    lower;

    higher = ft_find_higher_neighbor(num, dst);
    lower = ft_find_lower_neighbor(num, dst);
    if (higher == num)
    {
        ft_rotate_to_bottom(B, stacks, lower);
        ft_bust_a_move(PB, stacks);
    }
    else if (lower == num)
    {
        ft_rotate_to_top(B, stacks, higher);
        ft_bust_a_move(PB, stacks);
    }
    (void)src;
}

void    ft_insertion_sort(t_stacks *stacks)
{
    t_chunk chunk;

    chunk.size = 20;
    chunk.min = 0;
    chunk.max = 19;
    chunk.pushed = 0;
    while(chunk.pushed < chunk.size)
    {
        while (!ft_is_elem_of_chunk(stacks->a.array[0], &chunk))
            ft_bust_a_move(RA, stacks);
        if (chunk.pushed == 0)
        {
            ft_bust_a_move(PB, stacks);
            chunk.pushed++;
        }
        else
        {
            ft_rotate_and_push(stacks, stacks->a.array[0], &stacks->b, &stacks->a);
        }
    }
}

