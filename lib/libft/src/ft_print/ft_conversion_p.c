/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:46:40 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:30:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_convert_p(t_label *label, bool fastprint)
{
	unsigned long	num;

	num = (unsigned long)va_arg(label->args, void *);
	if (fastprint)
	{
		ft_putptr(num, &label->count);
		return ;
	}
	ft_print_p(label, num);
}

void	ft_print_p(t_label *label, unsigned long num)
{
	int	numlen;

	if (num)
		numlen = ft_count_digits(0, 16, num) + 2;
	else
		numlen = 5;
	if (numlen >= label->width)
		label->width = 0;
	else
		label->width -= numlen;
	while (!label->minus && label->width--)
		ft_putchar(' ', &label->count);
	ft_putptr(num, &label->count);
	while (label->minus && label->width--)
		ft_putchar(' ', &label->count);
}
