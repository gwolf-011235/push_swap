/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:10:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:11:02 by gwolf            ###   ########.fr       */
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

int32_t	ft_count_rot_top(uint32_t num, t_stack *stack)
{
	uint32_t	index;

	index = ft_search_from_top(stack, num);
	if (index < (stack->size / 2))
		return (index);
	else
		return ((stack->size - index + 1) * -1);
}

int32_t	ft_count_rot_bot(uint32_t num, t_stack *stack)
{
	uint32_t	index;

	index = ft_search_from_top(stack, num);
	if (index < (stack->size / 2))
		return (index +1);
	else
		return ((stack->size - index) * -1);
}
