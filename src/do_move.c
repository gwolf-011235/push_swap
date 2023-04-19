/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:12:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:16:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bust_some_moves(t_moves move, t_data *data, uint32_t repeat)
{
	while (repeat--)
	{
		ft_bust_a_move(move, data);
	}
}

void	ft_bust_a_move(t_moves move, t_data *data)
{
	if (move == PA)
		ft_push(&data->a, &data->b);
	else if (move == PB)
		ft_push(&data->b, &data->a);
	else if (move == SA)
		ft_swap(&data->a);
	else if (move == SB)
		ft_swap(&data->b);
	else if (move == SS)
		ft_double_swap(&data->a, &data->b);
	else if (move == RA)
		ft_rotate(&data->a);
	else if (move == RB)
		ft_rotate(&data->b);
	else if (move == RR)
		ft_double_rotate(&data->a, &data->b);
	else if (move == RRA)
		ft_rev_rotate(&data->a);
	else if (move == RRB)
		ft_rev_rotate(&data->b);
	else if (move == RRR)
		ft_double_rev_rotate(&data->a, &data->b);
	ft_handle_move(move, data);
}

void	ft_handle_move(t_moves move, t_data *data)
{
	if (data->mode == SILENT)
		return ;
	else if (data->mode == PRINT)
		ft_print_move_string(move);
	else if (data->mode == ENQUEUE)
	{
		if (!ft_enqueue(&data->moves, move))
			ft_cleanup_and_leave(data, true);
	}
}
