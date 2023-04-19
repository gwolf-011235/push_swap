/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:15:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:17:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_move_string(t_moves move)
{
	if (move == SA)
		ft_printf("sa\n");
	else if (move == SB)
		ft_printf("sb\n");
	else if (move == SS)
		ft_printf("ss\n");
	else if (move == PA)
		ft_printf("pa\n");
	else if (move == PB)
		ft_printf("pb\n");
	else if (move == RA)
		ft_printf("ra\n");
	else if (move == RB)
		ft_printf("rb\n");
	else if (move == RR)
		ft_printf("rr\n");
	else if (move == RRA)
		ft_printf("rra\n");
	else if (move == RRB)
		ft_printf("rrb\n");
	else if (move == RRR)
		ft_printf("rrr\n");
	else
		return ;
}

void	ft_print_moves_queue(t_queue *moves)
{
	t_moves	move;

	if (moves->head == NULL)
		return ;
	while (moves->head)
	{
		move = ft_dequeue(moves);
		if (move == UNDEFINED)
			return ;
		ft_print_move_string(move);
	}
}