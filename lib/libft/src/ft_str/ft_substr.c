/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:07:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 12:57:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/* Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’ */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	i = 0;
	ptr = (char *) malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s[start] && len--)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
