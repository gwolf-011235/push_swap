/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:55:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 19:06:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint32_t	ft_find_next_above_in_chunk(uint32_t target, t_stack *stack,
	t_chunk *chunk)
{
	uint32_t	neighbor;
	uint32_t	i;

	neighbor = UINT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] > target && stack->array[i] < neighbor
			&& ft_is_elem_of_chunk(stack->array[i], chunk))
			neighbor = stack->array[i];
		i++;
	}
	if (neighbor == UINT_MAX)
		return (target);
	else
		return (neighbor);
}

uint32_t	ft_find_next_below_in_chunk(uint32_t target, t_stack *stack,
	t_chunk *chunk)
{
	uint32_t	neighbor;
	uint32_t	i;

	neighbor = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < target && stack->array[i] > neighbor
			&& ft_is_elem_of_chunk(stack->array[i], chunk))
			neighbor = stack->array[i];
		i++;
	}
	if (neighbor == 0)
		return (target);
	else
		return (neighbor);
}

int32_t	ft_abs(int32_t num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
