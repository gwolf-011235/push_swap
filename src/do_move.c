/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:12:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/12 17:36:44 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bust_some_moves(uint8_t move, t_data *data, uint32_t repeat)
{
	while (repeat--)
	{
		ft_bust_a_move(move, data);
	}
}

void	ft_bust_a_move(uint8_t move, t_data *data)
{
	if (move == SA)
		ft_swap(&data->a);
	else if (move == SB)
		ft_swap(&data->b);
	else if (move == PA)
		ft_push(&data->a, &data->b);
	else if (move == PB)
		ft_push(&data->b, &data->a);
	else if (move == RA)
		ft_rotate(&data->a);
	else if (move == RB)
		ft_rotate(&data->b);
	else if (move == RRA)
		ft_rev_rotate(&data->a);
	else if (move == RRB)
		ft_rev_rotate(&data->b);
	else if (move == 255)
		ft_checker_talks(data, false);
	if (!ft_enqueue(&data->moves, move))
		ft_cleanup_and_leave(data, true);
}
