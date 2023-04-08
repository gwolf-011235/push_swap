/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:04:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 17:17:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint32_t	ft_count_rot_top(uint32_t num, t_stack *stack)
{
	uint32_t	pos;

	pos = ft_search_from_top(stack, num);
	if (pos > (stack->size / 2))
		return (stack->size - pos + 1);
	else
		return (pos);
}

uint32_t	ft_count_rot_bot(uint32_t num, t_stack *stack)
{
	uint32_t	pos;

	pos = ft_search_from_top(stack, num);
	if (pos > (stack->size / 2))
		return (stack->size - pos);
	else
		return (pos + 1);
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
	else if (ft_count_rot_top(higher, &data->b)
		< ft_count_rot_bot(lower, &data->b))
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

void	ft_sort_complex(t_data *data)
{
	ft_prep_chunks(data);
	ft_presort_chunks(data);
	ft_insertion_sort(data, &data->chunks[data->div - 1]);
	ft_rotate_to_top(B, data, data->chunks[data->div - 1].max);
}
