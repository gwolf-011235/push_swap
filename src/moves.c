/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:37:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 20:39:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, uint8_t option)
{
	int	temp;

	if ((option == A || option == BOTH) && stacks->a.size > 1)
	{
		temp = stacks->a.array[0];
		stacks->a.array[0] = stacks->a.array[1];
		stacks->a.array[1] = temp;
	}
	if ((option == B || option == BOTH) && stacks->b.size > 1)
	{
		temp = stacks->b.array[0];
		stacks->b.array[0] = stacks->b.array[1];
		stacks->b.array[1] = temp;
	}
}

void	ft_push(t_stacks *stacks, uint8_t option)
{
	if (option == A && stacks->b.size > 0)
	{
		ft_memmove(stacks->a.array + 1, stacks->a.array, stacks->a.size * sizeof(int));
		stacks->a.array[0] = stacks->b.array[0];
		ft_memmove(stacks->b.array, stacks->b.array + 1, stacks->b.size * sizeof(int));
		stacks->a.size++;
		stacks->b.size--;
	}
	else if (option == B && stacks->a.size > 0)
	{
		ft_memmove(stacks->b.array + 1, stacks->b.array, stacks->b.size * sizeof(int));
		stacks->b.array[0] = stacks->a.array[0];
		ft_memmove(stacks->a.array, stacks->a.array + 1, stacks->a.size * sizeof(int));
		stacks->a.size--;
		stacks->b.size++;
	}
}

void	ft_rotate(t_stacks *stacks, uint8_t option)
{
	int	temp;

	if ((option == A || option == BOTH) && stacks->a.size > 1)
	{
		temp = stacks->a.array[0];
		ft_memmove(stacks->a.array, stacks->a.array + 1, stacks->a.size * sizeof(int));
		stacks->a.array[stacks->a.size - 1] = temp;
	}
	if ((option == B || option == BOTH) && stacks->b.size > 1)
	{
		temp = stacks->b.array[0];
		ft_memmove(stacks->b.array, stacks->b.array + 1, stacks->b.size * sizeof(int));
		stacks->b.array[stacks->b.size - 1] = temp;
	}
}

void	ft_rev_rotate(t_stacks *stacks, uint8_t option)
{
	int	temp;

	if ((option == A || option == BOTH) && stacks->a.size > 1)
	{
		temp = stacks->a.array[stacks->a.size - 1];
		ft_memmove(stacks->a.array + 1, stacks->a.array, stacks->a.size * sizeof(int));
		stacks->a.array[0] = temp;
	}
	if ((option == B || option == BOTH) && stacks->b.size > 1)
	{
		temp = stacks->b.array[stacks->b.size - 1];
		ft_memmove(stacks->b.array + 1, stacks->b.array, stacks->b.size * sizeof(int));
		stacks->b.array[0] = temp;
	}
}
