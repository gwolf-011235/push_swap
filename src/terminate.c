/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:27:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/14 16:48:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_terminate(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_cleanup_and_leave(t_data *data, bool error)
{
	if (data->a.array)
		free(data->a.array);
	if (data->b.array)
		free(data->b.array);
	if (data->store.key)
		free(data->store.key);
	if (data->store.value)
		free(data->store.value);
	if (data->chunks)
		free(data->chunks);
	ft_killqueue(&data->moves);
	if (error)
		ft_terminate();
	else
		exit(0);
}
