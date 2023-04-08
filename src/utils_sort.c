/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:50:36 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 19:08:34 by gwolf            ###   ########.fr       */
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

bool	ft_rotate_to_top(uint8_t name, t_data *data, uint32_t num)
{
	uint32_t	position;
	t_stack		*stack;
	uint8_t		move[2];

	if (name == A)
	{
		stack = &data->a;
		move[0] = RA;
		move[1] = RRA;
	}
	else
	{
		stack = &data->b;
		move[0] = RB;
		move[1] = RRB;
	}
	position = ft_search_from_top(stack, num);
	if (position == 0)
		return (false);
	if (position < (stack->size / 2))
		ft_bust_some_moves(move[0], data, position);
	else
		ft_bust_some_moves(move[1], data, stack->size - position);
	return (true);
}

bool	ft_rotate_to_bottom(uint8_t name, t_data *data, uint32_t num)
{
	uint32_t	position;
	t_stack		*stack;
	uint8_t		move[2];

	if (name == A)
	{
		stack = &data->a;
		move[0] = RA;
		move[1] = RRA;
	}
	else
	{
		stack = &data->b;
		move[0] = RB;
		move[1] = RRB;
	}
	position = ft_search_from_top(stack, num);
	if (position == 0 && stack->size <= 1)
		return (false);
	if (position < (stack->size / 2))
		ft_bust_some_moves(move[0], data, position + 1);
	else
		ft_bust_some_moves(move[1], data, stack->size - position - 1);
	return (true);
}

uint32_t	ft_find_higher_neighbor(uint32_t target, t_stack *stack)
{
	uint32_t	neighbor;
	uint32_t	i;

	neighbor = UINT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] > target && stack->array[i] < neighbor)
			neighbor = stack->array[i];
		i++;
	}
	if (neighbor == UINT_MAX)
		return (target);
	else
		return (neighbor);
}

uint32_t	ft_find_lower_neighbor(uint32_t target, t_stack *stack)
{
	uint32_t	neighbor;
	uint32_t	i;

	neighbor = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < target && stack->array[i] > neighbor)
			neighbor = stack->array[i];
		i++;
	}
	if (neighbor == 0)
		return (target);
	else
		return (neighbor);
}
