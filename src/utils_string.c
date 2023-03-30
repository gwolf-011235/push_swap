/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:23:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/30 16:14:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move_like_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

uint32_t	ft_search_from_top(t_stack *stack, int32_t num)
{
	uint32_t	ret;
	uint32_t	i;

	ret = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == num)
			ret = i;
		i++;
	}
	return (ret);
}
