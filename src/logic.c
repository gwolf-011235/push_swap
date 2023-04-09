/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:04:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/09 08:23:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	uint32_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i + 1] < stack->array[i])
			return (false);
		i++;
	}
	return (true);
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
