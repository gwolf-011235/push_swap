/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:49:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:31:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_convert_u(t_label *label, bool fastprint)
{
	unsigned int	num;

	num = va_arg(label->args, unsigned int);
	if (fastprint)
	{
		ft_putnbr(num, &label->count);
		return ;
	}
	ft_flags_u(label, num);
	ft_print_u(label, num, &label->count);
}

void	ft_flags_u(t_label *label, unsigned int num)
{
	int	numlen;

	numlen = ft_count_digits(num, 10, 0);
	if (!label->precision && !num)
	{
		label->empty = true;
		numlen = 0;
	}
	else if (numlen >= label->precision)
		label->precision = 0;
	else
		label->precision -= numlen;
	if (numlen + label->precision >= label->width)
		label->width = 0;
	else
		label->width -= (numlen + label->precision);
}

void	ft_print_u(t_label *label, unsigned int num, size_t *count)
{
	char			padding;

	padding = ft_check_padding(label);
	while (label->minus && label->precision--)
		ft_putchar('0', count);
	while (!label->minus && label->width--)
		ft_putchar(padding, count);
	while (!label->minus && label->precision--)
		ft_putchar('0', count);
	if (!label->empty)
		ft_putnbr(num, count);
	while (label->minus && label->width--)
		ft_putchar(' ', count);
}
