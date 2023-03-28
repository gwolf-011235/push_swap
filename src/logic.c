/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:04:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/29 00:22:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ret_move_string(uint8_t move)
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
