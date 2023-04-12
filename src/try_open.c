/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:22:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/12 15:40:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_try_open(char **argv)
{
	int		fd;
	char	*temp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	temp = get_next_line(fd);
	while (temp)
	{
		argv[1] = temp;
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(argv[1]);
	}
	close(fd);
	return (true);
}
