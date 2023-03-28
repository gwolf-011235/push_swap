/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:27:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/29 01:01:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_terminate(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_cleanup_and_exit(t_stacks *stacks, bool error)
{
	if (stacks->a.array)
		free(stacks->a.array);
	if (stacks->b.array)
		free(stacks->b.array);
	if (stacks->store.key)
		free(stacks->store.key);
	if (stacks->store.value)
		free(stacks->store.value);
	if (error)
		ft_terminate();
	else
		exit(0);
}


