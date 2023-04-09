/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:18:03 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/09 08:23:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex(t_data *data)
{
	t_next	move;

	ft_prep_chunks(data);
	ft_presort_chunks(data);
	ft_insertion_sort(data, &data->chunks[data->div - 1]);
	ft_rotate_to_top(B, data, data->chunks[data->div - 1].max);
	ft_bust_some_moves(PA, data, data->chunks[data->div - 1].pushed);
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
