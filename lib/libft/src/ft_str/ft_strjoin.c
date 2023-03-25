/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:20:05 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:14:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/* Allocates (with malloc(3)) and returns a new string, which is the result of 
** the concatenation of ’s1’ and ’s2’ */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	new_string = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (*s1)
	{
		new_string[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new_string[i++] = *s2;
		s2++;
	}
	new_string[i] = 0;
	return (new_string);
}
