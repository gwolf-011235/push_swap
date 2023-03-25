/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:40:51 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:16:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/* Allocates (with malloc(3)) and returns an array of strings obtained by 
** splitting ’s’ using the character ’c’ as a delimiter. The array must end
** with a NULL pointer */
static size_t	ft_strlen_plus(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			word_count++;
		while (*s != c && *s)
			s++;
	}
	return (word_count);
}

static void	ft_delete_if_fail(char **array, size_t j)
{
	while (j--)
		free (array[j]);
	free(array);
	return ;
}

static char	**ft_fill_array(char const *s, char c, char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			array[j] = ft_substr(s, i, ft_strlen_plus((s + i), c));
			if (!array[j])
			{
				ft_delete_if_fail(array, j);
				return (NULL);
			}
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	array = malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!ft_fill_array(s, c, array))
		return (NULL);
	array[word_count] = NULL;
	return (array);
}
