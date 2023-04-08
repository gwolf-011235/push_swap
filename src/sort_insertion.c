/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:04:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 19:18:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	ft_count_rot_top(uint32_t num, t_stack *stack)
{
	uint32_t	index;

	index = ft_search_from_top(stack, num);
	if (index < (stack->size / 2))
		return (index);
	else
		return ((stack->size - index + 1) * -1);
}

int32_t	ft_count_rot_bot(uint32_t num, t_stack *stack)
{
	uint32_t	index;

	index = ft_search_from_top(stack, num);
	if (index < (stack->size / 2))
		return (index +1);
	else
		return ((stack->size - index) * -1);
}

void	ft_rot_and_push_b(uint32_t num, t_data *data, t_chunk *chunk)
{
	uint32_t	higher;
	uint32_t	lower;

	higher = ft_find_next_above_in_chunk(num, &data->b, chunk);
	lower = ft_find_next_below_in_chunk(num, &data->b, chunk);
	if (higher == num)
	{
		ft_rotate_to_top(B, data, lower);
	}
	else if (lower == num)
	{
		ft_rotate_to_bottom(B, data, higher);
	}
	else if (ft_abs(ft_count_rot_top(higher, &data->b))
		< ft_abs(ft_count_rot_bot(lower, &data->b)))
	{
		ft_rotate_to_bottom(B, data, higher);
	}
	else
	{
		ft_rotate_to_top(B, data, lower);
	}
	ft_bust_a_move(PB, data);
}

void	ft_insertion_sort(t_data *data, t_chunk *chunk)
{
	while (chunk->pushed < chunk->size)
	{
		if (chunk->pushed == 0)
		{
			ft_bust_a_move(PB, data);
		}
		else
		{
			ft_rot_and_push_b(data->a.array[0], data,
				&data->chunks[data->div - 1]);
		}
		chunk->pushed++;
	}
}
