/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:21:39 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:25:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd.h"

/* Outputs the string ’s’ to the given file descriptor followed by a newline */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd == -1)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
