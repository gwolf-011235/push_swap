/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:27:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/27 22:36:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_terminate(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_free_and_terminate(t_stacks *stacks)
{
	if (stacks->a.array)
		free(stacks->a.array);
	if (stacks->b.array)
		free(stacks->b.array);
	if (stacks->store.key)
		free(stacks->store.key);
	if (stacks->store.value)
		free(stacks->store.value);
	ft_terminate();
}
