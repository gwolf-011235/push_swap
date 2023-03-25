/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:11:17 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:31:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_init_label(t_label *label)
{
	label->hash = false;
	label->plus = false;
	label->space = false;
	label->minus = false;
	label->zero = false;
	label->width = -1;
	label->precision = -1;
	label->len = 0;
	label->neg = false;
	label->empty = false;
}

int	ft_check_sign_pos(t_label *label, char c)
{
	int	sign_pos;

	sign_pos = 0;
	if (c == 'i' && (label->plus || label->neg || label->space))
	{
		if (label->minus || (!label->minus && label->zero))
			sign_pos = 1;
		else if (!label->minus)
			sign_pos = 2;
	}
	if (c == 'x' && label->hash)
	{
		if (label->minus || (!label->minus && label->zero))
			sign_pos = 1;
		else if (!label->minus)
			sign_pos = 2;
	}
	return (sign_pos);
}

int	ft_count_digits(long num, int base, unsigned long num2)
{
	if (num2)
	{
		while (num2)
		{
			num2 /= base;
			num++;
		}
		return (num);
	}
	if (!num)
		return (1);
	if (num < 0)
	{
		num *= -1;
		num2 = 1;
	}
	while (num)
	{
		num /= base;
		num2++;
	}
	return (num2);
}

int	ft_check_sign(t_label *label)
{
	if (label->neg)
		return ('-');
	else if (label->plus)
		return ('+');
	else if (label->space)
		return (' ');
	else
		return ('!');
}

int	ft_check_padding(t_label *label)
{
	if (label->zero && !label->minus && !label->precision)
		return ('0');
	else
		return (' ');
}
