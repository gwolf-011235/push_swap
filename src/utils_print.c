/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:05:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 16:58:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stacks *stacks)
{
	uint32_t	i;

	ft_printf("The stacks are\n");
	i = 0;
	while (i < stacks->nums)
	{
		if (stacks->a.array[i] != 0)
			ft_printf("\t%5d", stacks->a.array[i]);
		if (stacks->b.array[i] != 0)
			ft_printf("\t%5d", stacks->b.array[i]);
		ft_printf("\n");
		i++;
		if (i >= stacks->a.size && i >= stacks->b.size)
			break ;
	}
	ft_printf("\t_____\t_____\n\t  a  \t  b\n\n");
	ft_printf("Sum of integers: %d\n", stacks->nums);
	ft_printf("Integers in stack a: %d\n", stacks->a.size);
	ft_printf("Integers in stack b: %d\n", stacks->b.size);
}
