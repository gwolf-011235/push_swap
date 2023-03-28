/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:40:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/29 00:44:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prep_input.h"

void	ft_prep_input(t_stacks *stacks)
{
	ft_assign_keys(stacks);
	ft_memcpy(stacks->a.array, stacks->store.key, sizeof(int32_t) * stacks->nums);
	stacks->a.size = stacks->nums;
	stacks->b.size = 0;
}

static void	ft_assign_keys(t_stacks *stacks)
{
	uint32_t	next_key;
	uint32_t	next_index;
	uint32_t	i;

	next_key = stacks->nums;
	i = 0;
	while (i < stacks->nums)
	{
		next_index = ft_find_next_max(&stacks->store, stacks->nums);
		stacks->store.key[next_index] = next_key;
		next_key--;
		i++;
	}
}

static uint32_t	ft_find_next_max(t_store *store, uint32_t nums)
{
	int32_t		cur_max;
	uint32_t	cur_max_i;
	uint32_t	i;

	i = 0;
	while (i < nums)
	{
		cur_max = store->value[i];
		cur_max_i = i;
		if (store->key[i] == 0)
			break ;
		i++;
	}
	i = 0;
	while (i < nums)
	{
		if (store->value[i] > cur_max && store->key[i] == 0)
		{
			cur_max = store->value[i];
			cur_max_i = i;
		}
		i++;
	}
	return (cur_max_i);
}
