/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:45:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:31:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_convert_s(t_label *label, bool fastprint)
{
	const char	*s;
	int			strlen;

	s = va_arg(label->args, const char *);
	if (fastprint)
	{
		ft_putstr(s, &label->count, -1);
		return ;
	}
	strlen = ft_flags_s(label, s);
	ft_print_s(label, s, strlen);
}

int	ft_flags_s(t_label *label, const char *s)
{
	int	strlen;

	if (s)
		strlen = ft_strlen(s);
	else
	{
		label->empty = true;
		strlen = 6;
	}
	if (!label->precision)
		strlen = 0;
	if (label->precision > 0 && strlen > label->precision)
		strlen = label->precision;
	if (strlen >= label->width)
		label->width = 0;
	else if (!label->empty || (label->empty && strlen == 6))
		label->width -= strlen;
	return (strlen);
}

void	ft_print_s(t_label *label, const char *s, int strlen)
{
	while (!label->minus && label->width--)
		ft_putchar(' ', &label->count);
	ft_putstr(s, &label->count, strlen);
	while (label->minus && label->width--)
		ft_putchar(' ', &label->count);
}
