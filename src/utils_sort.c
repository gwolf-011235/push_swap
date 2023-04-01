/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:50:36 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/31 14:06:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint32_t	ft_search_from_top(t_stack *stack, uint32_t num)
{
	uint32_t	ret;
	uint32_t	i;

	ret = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == num)
			ret = i;
		i++;
	}
	return (ret);
}

bool	ft_rotate_to_top(uint8_t name, t_stacks *stacks, uint32_t num)
{
	uint32_t	position;
	t_stack		*stack;
	uint8_t		move[2];

	if (name == A)
	{
		stack = &stacks->a;
		move[0] = RA;
		move[1] = RRA;
	}
	else
	{
		stack = &stacks->b;
		move[0] = RB;
		move[1] = RRB;
	}
	position = ft_search_from_top(stack, num);
	if (position == 0)
		return (false);
	if (position < (stack->size / 2))
		ft_bust_some_moves(move[0], stacks, position);
	else
		ft_bust_some_moves(move[1], stacks, stack->size - position);
	return (true);
}
