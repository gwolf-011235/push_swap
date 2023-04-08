/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:04:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 08:41:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prep_chunks(t_data *data)
{
	uint32_t	size;
	uint32_t	i;

	size = data->nums / data->div;
	i = 1;
	data->chunks[0].size = size;
	data->chunks[0].min = 1;
	data->chunks[0].max = size;
	data->chunks[0].pushed = 0;
	while (i < (data->div - 1))
	{
		data->chunks[i].size = size;
		data->chunks[i].min = data->chunks[i - 1].max + 1;
		data->chunks[i].max = size * (i + 1);
		data->chunks[i].pushed = 0;
		i++;
	}
	data->chunks[i].size = size + (data->nums % data->div);
	data->chunks[i].min = data->chunks[i - 1].max + 1;
	data->chunks[i].max = data->nums;
	data->chunks[i].pushed = 0;
}

bool	ft_is_elem_of_chunk(uint32_t num, t_chunk *chunk)
{
	return (num >= chunk->min && num <= chunk->max);
}

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

void	ft_rot_and_push_b(uint32_t num, t_data *data)
{
	uint32_t	higher;
	uint32_t	lower;

	higher = ft_find_higher_neighbor(num, &data->b);
	lower = ft_find_lower_neighbor(num, &data->b);
	if (higher == num)
	{
		ft_rotate_to_bottom(B, data, lower);
	}
	else if (lower == num)
	{
		ft_rotate_to_top(B, data, higher);
	}
	else if (ft_count_rot_top(higher, &data->b)
		< ft_count_rot_bot(lower, &data->b))
	{
		ft_rotate_to_top(B, data, higher);
	}
	else
	{
		ft_rotate_to_bottom(B, data, lower);
	}
	ft_bust_a_move(PB, data);
}

void	ft_chunk_update_bounds(t_data *data, t_chunk *chunk)
{
	if (chunk->pushed == 0)
	{
		chunk->bounds[0] = data->a.array[0];
		chunk->bounds[1] = data->a.array[0];
	}
	else if (ft_is_elem_of_chunk(data->b.array[0], chunk))
	{
		if (!ft_is_elem_of_chunk(data->b.array[data->b.size - 1], chunk))
			chunk->bounds[1] = data->a.array[0];
	}
	else if (ft_is_elem_of_chunk(data->b.array[data->b.size - 1], chunk))
		chunk->bounds[0] = data->a.array[0];
	else if (chunk->pushed == 1)
		chunk->bounds[1] = data->a.array[0];
}

void	ft_chunk_prep_push(t_data *data, t_chunk *chunk, t_chunk *two)
{
	if (chunk->pushed == 0 && two->pushed == 0)
		ft_bust_a_move(PB, data);
	else if (chunk->pushed == 0)
	{
		ft_rotate_to_top(B, data, two->bounds[1]);
		ft_bust_a_move(PB, data);
	}
	else if (ft_is_elem_of_chunk(data->b.array[0], chunk))
		ft_bust_a_move(PB, data);
	else if (ft_is_elem_of_chunk(data->b.array[data->b.size - 1], chunk))
		ft_bust_a_move(PB, data);
	else
	{
		ft_rotate_to_top(B, data, chunk->bounds[0]);
		ft_bust_a_move(PB, data);
	}
	chunk->pushed++;
	

}

void	ft_presort_chunks(t_data *data)
{
	t_chunk	*one;
	t_chunk	*two;

	one = &data->chunks[0];
	two = &data->chunks[1];
	while ((one->pushed < one->size) || (two->pushed < two->size))	
	{
		if (ft_is_elem_of_chunk(data->a.array[0], one))
		{
			ft_chunk_update_bounds(data, one);
			ft_chunk_prep_push(data, one, two);	
		}
		else if (ft_is_elem_of_chunk(data->a.array[0], two))
		{
			ft_chunk_update_bounds(data, two);
			ft_chunk_prep_push(data, two, one);
		}
		else
			ft_bust_a_move(RA, data);	
	}
	ft_rotate_to_top(B, data, one->bounds[1]);
	ft_print_stacks(data);
}

void	ft_insertion_sort(t_data *data, t_chunk *chunk)
{
	while(chunk->pushed < chunk->size)
	{
		while (!ft_is_elem_of_chunk(data->a.array[0], chunk))
			ft_bust_a_move(RA, data);
		if (chunk->pushed == 0)
	{
		ft_bust_a_move(PB, data);
	}
	else
	{
		ft_rot_and_push_b(data->a.array[0], data);
	}
	chunk->pushed++;
	}
}
