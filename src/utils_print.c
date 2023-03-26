/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:05:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 15:43:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *stack)
{
	uint32_t	i;

	ft_printf("The stacks are\n");
	i = 0;
	while (i < stack->nums)
	{
		if (stack->a[i] != 0)
			ft_printf("\t%5d", stack->a[i]);
		if (stack->b[i] != 0)
			ft_printf("\t%5d", stack->b[i]);
		ft_printf("\n");
		i++;
		if (i >= stack->a_count && i >= stack->b_count)
			break ;
	}
	ft_printf("\t_____\t_____\n\t  a  \t  b\n\n");
	ft_printf("Sum of integers: %d\n", stack->nums);
	ft_printf("Integers in stack a: %d\n", stack->a_count);
	ft_printf("Integers in stack b: %d\n", stack->b_count);
}
