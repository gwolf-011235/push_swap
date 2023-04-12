/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:23:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/12 11:37:44 by gwolf            ###   ########.fr       */
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
	while (str[i] == ' ')
		i++;
	return (i);
}

bool	ft_check_overflow(char *str)
{
	int64_t		num;
	uint32_t	len;

	len = ft_move_like_atoi(str);
	if ((str[0] != '-' && len > 10) || (str[0] == '-' && len > 11))
		return (true);
	num = ft_atoi(str);
	if ((str[0] != '-' && num < 0) || (str[0] == '-' && num > 0))
		return (true);
	return (false);
}
