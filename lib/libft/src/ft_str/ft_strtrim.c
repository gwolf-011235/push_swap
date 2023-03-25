/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:32:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 12:55:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/* Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
** specified in ’set’ removed from the beginning and the end of the string */
static char	check_set(char const c, char const *set)
{
	size_t	hit;

	hit = 0;
	while (*set)
	{
		if (*set == c)
			hit++;
		set++;
	}
	if (hit)
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (check_set(s1[start], set))
		start++;
	while (check_set(s1[end], set))
		end--;
	trim = ft_substr(s1, start, (end - start + 1));
	return (trim);
}
