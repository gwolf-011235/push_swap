/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:25:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 15:34:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_check_input(int argc, char **argv, uint32_t *count)
{
	int	i;

	while (argc-- > 1)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (i > 0)
				(*count)++;
			if (!ft_is_valid_num(&argv[argc][i]))
				ft_terminate();
			i += ft_move_like_atoi(&argv[argc][i]);
		}
	}
	return (true);
}

bool	ft_is_valid_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (false);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == ' ' || str[i] == '\0')
		return (true);
	else
		return (false);
}

int	ft_move_like_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}
