/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:44:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 12:53:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putchar(unsigned char c, size_t *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(const char *s, size_t *count, int strlen)
{
	if (!strlen)
		return ;
	if (!s)
	{
		if (strlen >= 6 || strlen == -1)
			*count += write (1, "(null)", 6);
		return ;
	}
	if (strlen == -1)
	{
		while (*s)
		{
			ft_putchar(*s, count);
			s++;
		}
	}
	else
	{
		while (*s && strlen--)
		{
			ft_putchar(*s, count);
			s++;
		}
	}
}

void	ft_putnbr(long nbr, size_t *count)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	*count += write(1, &"0123456789"[nbr % 10], 1);
}

void	ft_puthex(unsigned long nbr, size_t *count, char c)
{
	if (nbr > 15)
		ft_puthex(nbr / 16, count, c);
	if (c == 'X')
		*count += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		*count += write(1, &"0123456789abcdef"[nbr % 16], 1);
}

void	ft_putptr(unsigned long nbr, size_t *count)
{
	if (nbr)
	{
		*count += write(1, "0x", 2);
		ft_puthex(nbr, count, false);
	}
	else
		*count += write(1, "(nil)", 5);
}
