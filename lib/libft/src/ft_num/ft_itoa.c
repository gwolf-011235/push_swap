/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:30:33 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:27:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

static int	ft_count_digits(long temp)
{
	int	digits;

	digits = 0;
	while (temp)
	{
		digits++;
		temp /= 10;
	}
	return (digits);
}

static char	*ft_fill_array(char *string, long temp, int sign)
{
	int	i;
	int	digits;

	if (temp == 0)
		digits = 1;
	else
		digits = ft_count_digits(temp);
	string[digits] = 0;
	i = digits - 1;
	if (sign == -1)
	{
		string[0] = '-';
		string[digits + 1] = 0;
		i++;
	}
	while (digits)
	{
		string[i] = temp % 10 + 48;
		temp /= 10;
		digits--;
		i--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		digits;
	long	temp;
	char	*string;

	temp = n;
	sign = 1;
	if (n == 0)
		digits = 1;
	else
		digits = ft_count_digits(n);
	if (temp < 0)
	{
		sign = -1;
		temp = temp * sign;
		digits++;
	}
	string = malloc(sizeof(char) * digits + 1);
	if (!string)
		return (NULL);
	ft_fill_array(string, temp, sign);
	return (string);
}
