/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:53:05 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/01 15:22:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_data *data)
{
	data->cur_half = data->nums / 2;
	data->divide_count = 1;
	data->min = 1;
	ft_split_a(data);

}

void	ft_split_a(t_data *data)
{
	uint32_t	i;
	uint32_t	temp_size;

	i = 0;
	temp_size = data->a.size;
	while (i < temp_size)
	{
		if (data->a.array[0] <= data->cur_half)
			ft_bust_a_move(PB, data);
		else
			ft_bust_a_move(RA, data);
		i++;
	}
	ft_print_stacks(data);
}
