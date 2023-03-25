/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:28:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:13:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strdup(const char *s)
{
	char	*copy_str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s) + 1;
	copy_str = malloc(size);
	if (!copy_str)
		return (NULL);
	while (*s)
	{
		copy_str[i] = *s;
		s++;
		i++;
	}
	copy_str[i] = 0;
	return (copy_str);
}
