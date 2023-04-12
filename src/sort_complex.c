/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:18:03 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/10 23:26:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex(t_data *data)
{
	t_next		move;
	uint32_t	i;

	ft_prep_chunks(data);
	i = 0;
	while (i < data->div - 2)
	{
		ft_quick_chunk_sort(data, &data->chunks[i], &data->chunks[i + 1]);
		i++;
	}
	if (data->a.size > 3)
		ft_bust_some_moves(PB, data, data->a.size - 3);
	ft_simple_sort(data);
	while (data->b.size > 0)
	{
		move = ft_calc_next_move(data);
		ft_exec_next_move(data, &move);
	}
	ft_rotate_to_top(A, data, 1);
	ft_merge_dupl_moves(&data->moves);
	ft_print_moves(&data->moves);
}

void	ft_exec_next_move(t_data *data, t_next *move)
{
	if (move->top)
		ft_rotate_to_top(A, data, move->target);
	else
		ft_rotate_to_bottom(A, data, move->target);
	ft_rotate_to_top(B, data, data->b.array[move->index]);
	ft_bust_a_move(PA, data);
}
