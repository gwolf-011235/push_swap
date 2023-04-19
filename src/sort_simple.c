/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:56:24 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:00:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_data *data)
{
	if (data->a.size == 2)
		ft_sort_two(data);
	else if (data->a.size == 3)
		ft_sort_three(data);
	else if (data->a.size == 4)
		ft_sort_four(data);
	else if (data->a.size == 5)
		ft_sort_five(data);
}

void	ft_sort_two(t_data *data)
{
	if (data->a.array[0] > data->a.array[1])
		ft_bust_a_move(SA, data);
}

void	ft_sort_three(t_data *data)
{
	if (ft_is_sorted(&data->a))
		return ;
	if (data->a.array[0] < data->a.array[1])
	{
		if (data->a.array[0] < data->a.array[2])
		{
			ft_bust_a_move(RRA, data);
			ft_bust_a_move(SA, data);
		}
		else
			ft_bust_a_move(RRA, data);
	}
	else
	{
		if (data->a.array[0] < data->a.array[2])
			ft_bust_a_move(SA, data);
		else if (data->a.array[0] > data->a.array[2]
			&& data->a.array[1] > data->a.array[2])
		{
			ft_bust_a_move(RA, data);
			ft_bust_a_move(SA, data);
		}
		else
			ft_bust_a_move(RA, data);
	}
}

void	ft_sort_four(t_data *data)
{
	ft_rotate_to_top(A, data, 1);
	if (ft_is_sorted(&data->a))
		return ;
	ft_bust_a_move(PB, data);
	ft_sort_three(data);
	ft_bust_a_move(PA, data);
}

void	ft_sort_five(t_data *data)
{
	ft_rotate_to_top(A, data, 1);
	ft_bust_a_move(PB, data);
	ft_rotate_to_top(A, data, 2);
	ft_bust_a_move(PB, data);
	ft_sort_three(data);
	ft_bust_a_move(PA, data);
	ft_bust_a_move(PA, data);
}
