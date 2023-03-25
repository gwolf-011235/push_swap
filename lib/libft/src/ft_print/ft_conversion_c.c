/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:44:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:30:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_convert_c(t_label *label, bool fastprint)
{
	unsigned char	c;

	c = va_arg(label->args, int);
	if (fastprint)
	{
		ft_putchar(c, &label->count);
		return ;
	}
	ft_print_c(label, c);
}

void	ft_print_c(t_label *label, unsigned char c)
{
	if (!label->width)
		label->width = 1;
	label->width--;
	while (!label->minus && label->width--)
		ft_putchar(' ', &label->count);
	ft_putchar(c, &label->count);
	while (label->minus && label->width--)
		ft_putchar(' ', &label->count);
}
