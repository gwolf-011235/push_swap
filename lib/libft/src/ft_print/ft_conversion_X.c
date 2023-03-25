/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:33:48 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:31:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_convert_x_big(t_label *label, bool fastprint)
{
	unsigned int	num;

	num = va_arg(label->args, unsigned int);
	if (fastprint)
	{
		ft_puthex(num, &label->count, 'X');
		return ;
	}
	ft_flags_x_big(label, num);
	ft_print_x_big(label, num, &label->count);
}

void	ft_flags_x_big(t_label *label, unsigned int num)
{
	int	numlen;

	numlen = 0;
	if (!label->precision && !num)
		label->empty = true;
	else
		numlen = ft_count_digits(num, 16, 0);
	if (label->hash && num)
		numlen += 2;
	if (numlen >= label->precision)
		label->precision = 0;
	else
		label->precision -= numlen;
	if (numlen + label->precision >= label->width)
		label->width = 0;
	else
		label->width -= (numlen + label->precision);
}

void	ft_print_x_big(t_label *label, unsigned int num, size_t *count)
{
	char	padding;
	int		sign_pos;

	padding = ft_check_padding(label);
	sign_pos = ft_check_sign_pos(label, 'x');
	if (sign_pos == 1 && num)
		ft_putstr("0X", count, 2);
	while (label->minus && label->precision--)
		ft_putchar('0', count);
	while (!label->minus && label->width--)
		ft_putchar(padding, count);
	if (sign_pos == 2 && num)
		ft_putstr("0X", count, 2);
	while (!label->minus && label->precision--)
		ft_putchar('0', count);
	if (!label->empty)
		ft_puthex(num, count, 'X');
	while (label->minus && label->width--)
		ft_putchar(' ', count);
}
