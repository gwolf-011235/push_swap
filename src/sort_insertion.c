/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:04:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/12 15:45:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
