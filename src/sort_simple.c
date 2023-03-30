/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:56:24 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/30 14:04:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_stacks *stacks)
{
	if (stacks->nums == 2)
		ft_sort_two(stacks);
	else if (stacks->nums == 3)
		ft_sort_three(stacks);
}

void	ft_sort_two(t_stacks *stacks)
{
	if (stacks->a.array[0] > stacks->a.array[1])
		ft_bust_a_move(SA, stacks);
}

void	ft_sort_three(t_stacks *stacks)
{
	t_stack	*a;

	a = &stacks->a;
	if (a->array[0] < a->array[1])
	{
		if (a->array[0] < a->array[2])
		{
			ft_bust_a_move(RRA, stacks);
			ft_bust_a_move(SA, stacks);
		}
		else
			ft_bust_a_move(RRA, stacks);
	}
	else
	{
		if (a->array[0] < a->array[2])
			ft_bust_a_move(SA, stacks);
		else if (a->array[0] > a->array[2] && a->array[1] > a->array[2])
		{
			ft_bust_a_move(RA, stacks);
			ft_bust_a_move(SA, stacks);
		}
		else
			ft_bust_a_move(RA, stacks);
	}
}
