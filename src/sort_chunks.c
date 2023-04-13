/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:30:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/12 15:42:50 by gwolf            ###   ########.fr       */
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
	if (data->div > 1)
	{
		data->chunks[i].size = size + (data->nums % data->div);
		data->chunks[i].min = data->chunks[i - 1].max + 1;
		data->chunks[i].max = data->nums;
		data->chunks[i].pushed = 0;
	}
}

bool	ft_is_elem_of_chunk(uint32_t num, t_chunk *chunk)
{
	return (num >= chunk->min && num <= chunk->max);
}

void	ft_quick_chunk_sort(t_data *data, t_chunk *one, t_chunk *two)
{
	while ((one->pushed < one->size || two->pushed < two->size))
	{
		if (ft_is_elem_of_chunk(data->a.array[0], one))
		{
			if (two->pushed == 0)
				ft_bust_a_move(PB, data);
			else
			{
				ft_bust_a_move(PB, data);
				ft_bust_a_move(RB, data);
			}
			one->pushed++;
		}
		else if (ft_is_elem_of_chunk(data->a.array[0], two))
		{
			ft_bust_a_move(PB, data);
			two->pushed++;
		}
		else
			ft_bust_a_move(RA, data);
	}
}
