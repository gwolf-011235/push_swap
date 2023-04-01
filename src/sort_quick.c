/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:53:05 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/01 14:18:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_stacks *stacks)
{
	stacks->cur_half = stacks->nums / 2;
	stacks->divide_count = 1;
	ft_split_a(stacks);

}

void	ft_split_a(t_stacks *stacks)
{
	uint32_t	i;
	uint32_t	temp_size;

	i = 0;
	temp_size = stacks->a.size;
	while (i < temp_size)
	{
		if (stacks->a.array[i] < stacks->cur_half)
			ft_bust_a_move(PB, stacks);
		i++;
	}
	ft_print_stacks(stacks);
}