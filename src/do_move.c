/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:12:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/31 09:14:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bust_some_moves(uint8_t move, t_stacks *stacks, uint32_t repeat)
{
	while (repeat--)
	{
		ft_bust_a_move(move, stacks);
	}
}

void	ft_bust_a_move(uint8_t move, t_stacks *stacks)
{
	if (move == SA)
		ft_swap(&stacks->a);
	else if (move == SB)
		ft_swap(&stacks->b);
	else if (move == PA)
		ft_push(&stacks->a, &stacks->b);
	else if (move == PB)
		ft_push(&stacks->b, &stacks->a);
	else if (move == RA)
		ft_rotate(&stacks->a);
	else if (move == RB)
		ft_rotate(&stacks->b);
	else if (move == RRA)
		ft_rev_rotate(&stacks->a);
	else if (move == RRB)
		ft_rev_rotate(&stacks->b);
	if (!ft_enqueue(&stacks->moves, ft_return_move_string(move)))
		ft_cleanup_and_exit(stacks, true);
}
