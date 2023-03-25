/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:37:48 by gwolf             #+#    #+#             */
/*   Updated: 2023/02/02 19:41:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

t_ftptr	ft_look_up_ptr(unsigned char c)
{
	static const t_ftptr	look_up_table[128] = {
	['c'] = ft_convert_c,
	['s'] = ft_convert_s,
	['p'] = ft_convert_p,
	['i'] = ft_convert_i,
	['d'] = ft_convert_i,
	['u'] = ft_convert_u,
	['x'] = ft_convert_x,
	['X'] = ft_convert_x_big,
	['%'] = ft_convert_percent,
	};

	return (look_up_table[c]);
}

bool	ft_check_conv(t_label *label, unsigned char c)
{
	t_ftptr	ftptr;
	bool	fastprint;

	if (!label->len)
		fastprint = true;
	else
		fastprint = false;
	label->len++;
	ftptr = ft_look_up_ptr(c);
	ftptr(label, fastprint);
	return (true);
}

int	ft_check_flags(t_label *label, char c)
{
	if (c == '#')
		label->hash = true;
	else if (c == '+')
		label->plus = true;
	else if (c == ' ')
		label->space = true;
	else if (c == '-')
		label->minus = true;
	else if (c == '0')
		label->zero = true;
	else
		return (0);
	label->len++;
	return (1);
}

bool	ft_check_string(t_label *label, const char *format)
{
	int	i;

	i = 0;
	while (ft_check_flags(label, format[i]))
		i++;
	label->width = ft_atoi(&format[i]);
	if (label->width)
		i += ft_count_digits(label->width, 10, 0);
	if (format[i] == '.')
	{
		i++;
		label->zero = false;
		label->precision = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	label->len = i;
	if (ft_strchr("cspdiuxX%", format[i]))
		return (ft_check_conv(label, format[i]));
	return (false);
}

int	ft_printf(const char *format, ...)
{
	size_t			i;
	static t_label	label;

	va_start(label.args, format);
	label.count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			ft_init_label(&label);
			if (ft_check_string(&label, format + i + 1))
				i += label.len;
			else
				return (-1);
		}
		else if (format[i] == '%' && format[i + 1] == 0)
			return (-1);
		else
			label.count += write(1, &format[i], 1);
		i++;
	}
	va_end(label.args);
	return (label.count);
}
