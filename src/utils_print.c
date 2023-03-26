/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:05:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 10:21:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *stack)
{
	uint32_t	i;

	i = 0;
	while (i < stack->nums)
	{
		if (stack->a[i] != 0)
			ft_printf(" %2d", stack->a[i]);
		if (stack->b[i] != 0)
			ft_printf(" %2d", stack->b[i]);
		ft_printf("\n");
		i++;
		if (i >= stack->a_count && i >= stack->b_count)
			break ;
	}
	ft_printf("_____ _____\n  a     b\n");
}