/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:12:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/13 07:24:18 by gwolf            ###   ########.fr       */
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

char	*ft_return_move_string(uint8_t move)
{
	if (move == SA)
		return ("sa\n");
	else if (move == SB)
		return ("sb\n");
	else if (move == SS)
		return ("ss\n");
	else if (move == PA)
		return ("pa\n");
	else if (move == PB)
		return ("pb\n");
	else if (move == RA)
		return ("ra\n");
	else if (move == RB)
		return ("rb\n");
	else if (move == RR)
		return ("rr\n");
	else if (move == RRA)
		return ("rra\n");
	else if (move == RRB)
		return ("rrb\n");
	else if (move == RRR)
		return ("rrr\n");
	else
		return (NULL);
}
