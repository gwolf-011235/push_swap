/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_next_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:01:20 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/09 00:02:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_next	ft_calc_next_move(t_data *data)
{
	t_next		move;
	int32_t		cost[3];
	uint32_t	i;

	move.cost = INT_MAX;
	i = 0;
	while (i < data->b.size)
	{
		cost[A] = ft_calc_insert_cost(data->b.array[i], &data->a, &move);
		cost[B] = ft_count_rot_top(data->b.array[i], &data->b);
		cost[SUM] = ft_calc_sum_cost(cost[A], cost[B]);
		if (cost[SUM] < move.cost)
		{
			ft_update_next_move(&move, cost[SUM], i);
		}
		i++;
	}
	return (move);
}

int32_t	ft_calc_insert_cost(uint32_t num, t_stack *stack, t_next *move)
{
	uint32_t	higher;
	int32_t		cost_higher;
	uint32_t	lower;
	int32_t		cost_lower;

	higher = ft_find_higher_neighbor(num, stack);
	lower = ft_find_lower_neighbor(num, stack);
	cost_higher = ft_count_rot_top(higher, stack);
	cost_lower = ft_count_rot_bot(lower, stack);
	if (abs(cost_higher) < abs(cost_lower))
	{
		move->temp = higher;
		return (cost_higher);
	}
	else
	{
		move->temp = -lower;
		return (cost_lower);
	}
}

int32_t	ft_calc_sum_cost(int32_t cost_a, int32_t cost_b)
{
	int32_t	cost_sum;

	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			cost_sum = cost_a;
		else
			cost_sum = cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (-cost_a > -cost_b)
			cost_sum = -cost_a;
		else
			cost_sum = -cost_b;
	}
	else
		cost_sum = (abs(cost_a) + abs(cost_b));
	return (cost_sum);
}

void	ft_update_next_move(t_next *move, int32_t cost_sum, uint32_t i)
{
	move->cost = cost_sum;
	move->index = i;
	move->target = move->temp;
	if (move->target < 0)
	{
		move->top = false;
		move->target *= -1;
	}
	else
		move->top = true;
}
