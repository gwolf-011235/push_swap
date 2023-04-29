/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:23:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/29 12:29:51 by gwolf            ###   ########.fr       */
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

int	ft_try_next_num(const char *nptr, long num, int sign)
{
	long	new_num;

	new_num = num * 10 + *nptr - '0';
	if (new_num < num)
	{
		if (sign == 0)
			return (-1);
		else
			return (1);
	}
	num = num * 10 + *nptr - '0';
	if (num > INT_MAX && !sign)
		return (-1);
	else if ((num * sign) < INT_MIN)
		return (1);
	else
		return (2);
}

int	ft_atoi_modified(const char *nptr)
{
	long	num;
	long	check;
	int		sign;

	num = 0;
	sign = 0;
	while (*nptr == ' ' || (*nptr <= '\r' && *nptr >= '\t'))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		check = ft_try_next_num(nptr, num, sign);
		if (check == 2)
			num = num * 10 + *nptr - '0';
		else
			return (check);
		nptr++;
	}
	if (sign)
		num *= -1;
	return (num);
}

bool	ft_check_overflow(char *str)
{
	int32_t		num;

	num = ft_atoi_modified(str);
	if ((str[0] != '-' && num < 0) || (str[0] == '-' && num > 0))
		return (true);
	return (false);
}
