/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:04:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/13 07:24:08 by gwolf            ###   ########.fr       */
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
