/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:22:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:08:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temp;
	const unsigned char	*temp2;

	if (n == 0)
		return (0);
	temp = s1;
	temp2 = s2;
	i = 0;
	while (--n && temp[i] == temp2[i])
		i++;
	return (temp[i] - temp2[i]);
}
