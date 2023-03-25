/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:19:50 by gwolf             #+#    #+#             */
/*   Updated: 2022/10/23 10:59:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_overflow(const char *nptr, long num, int sign)
{
	long	new_num;

	new_num = num * 10 + *nptr - '0';
	if (new_num < num)
	{
		if (sign == 0)
			return (-1);
		else
			return (0);
	}
	else
		return (2);
}

int	ft_atoi(const char *nptr)
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
		check = ft_check_overflow(nptr, num, sign);
		if (check == 2)
			num = num * 10 + *nptr - '0';
		else
			return (check);
		nptr++;
	}
	if (sign)
		num *= -1;
	return ((int)num);
}
