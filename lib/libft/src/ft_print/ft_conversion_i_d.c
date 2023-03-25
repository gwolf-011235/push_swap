/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_i_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:47:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:30:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_convert_i(t_label *label, bool fastprint)
{
	int	num;

	num = va_arg(label->args, int);
	if (fastprint)
	{
		if (num == INT_MIN)
		{
			ft_putstr("-2147483648", &label->count, 11);
			return ;
		}
		if (num < 0)
		{
			ft_putchar('-', &label->count);
			num *= -1;
		}
		ft_putnbr(num, &label->count);
		return ;
	}
	ft_flags_i(label, num);
	ft_print_i(label, num, &label->count);
}

void	ft_flags_i(t_label *label, int num)
{
	int	numlen;

	numlen = 0;
	if (num < 0)
		label->neg = true;
	if (label->neg)
		num *= -1;
	if (!label->precision && !num)
		label->empty = true;
	else
		numlen = ft_count_digits(num, 10, 0);
	if (num == INT_MIN)
		numlen--;
	if (numlen >= label->precision)
		label->precision = 0;
	else
		label->precision -= numlen;
	if (label->plus || label->neg || label->space)
		numlen++;
	if (numlen + label->precision >= label->width)
		label->width = 0;
	else
		label->width -= (numlen + label->precision);
}

void	ft_print_i(t_label *label, int num, size_t *count)
{
	char	padding;
	char	sign;
	int		sign_pos;

	padding = ft_check_padding(label);
	sign = ft_check_sign(label);
	sign_pos = ft_check_sign_pos(label, 'i');
	if (sign_pos == 1)
		ft_putchar(sign, count);
	while (label->minus && label->precision--)
		ft_putchar('0', count);
	while (!label->minus && label->width--)
		ft_putchar(padding, count);
	if (sign_pos == 2)
		ft_putchar(sign, count);
	while (!label->minus && label->precision--)
		ft_putchar('0', count);
	if (!label->empty)
		ft_putnbr(num, count);
	while (label->minus && label->width--)
		ft_putchar(' ', count);
}
