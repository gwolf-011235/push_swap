/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:33:29 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 12:54:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (little[i] == 0)
		return ((char *)big);
	if (!len)
		return (0);
	while (len > 0 && big[i])
	{
		if (big[i] == little[k])
		{
			while (big[i + k] == little[k] && little[k] && len--)
				k++;
			if (!little[k])
				return ((char *)&big[i]);
			len += k;
		}
		len--;
		i++;
		k = 0;
	}
	return (NULL);
}
