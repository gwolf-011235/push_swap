/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:04:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/03 23:03:07 by gwolf            ###   ########.fr       */
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

void    ft_rotate_and_push(t_data *data, uint32_t num, t_stack *dst, t_stack *src)
{
    uint32_t    higher;
    uint32_t    lower;

    higher = ft_find_higher_neighbor(num, dst);
    lower = ft_find_lower_neighbor(num, dst);
    if (higher == num)
    {
        ft_rotate_to_bottom(B, data, lower);
    }
    else if (lower == num)
    {
        ft_rotate_to_top(B, data, higher);
    }
    else if (ft_count_rotate_top(higher, dst) < ft_count_rotate_bottom(lower, dst))
    {
	ft_rotate_to_top(B, data, higher);
    }
    else
    {
	ft_rotate_to_bottom(B, data, higher);
    }
    ft_bust_a_move(PB, data);
}

void    ft_insertion_sort(t_data *data)
{
    t_chunk chunk;

    chunk.size = 20;
    chunk.min = 0;
    chunk.max = 19;
    chunk.pushed = 0;
    while(chunk.pushed < chunk.size)
    {
        while (!ft_is_elem_of_chunk(data->a.array[0], &chunk))
            ft_bust_a_move(RA, data);
        if (chunk.pushed == 0)
        {
            ft_bust_a_move(PB, data);
        }
        else
        {
            ft_rotate_and_push(data, data->a.array[0], &data->b, &data->a);
        }
        chunk.pushed++;
    }
}

