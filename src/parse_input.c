/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:50:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/01 11:28:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

void	ft_parse_input(t_stacks *stacks, int argc, char **argv)
{
	ft_malloc_stacks(stacks);
	ft_extract_nums(stacks, argc, argv);
	ft_check_doubles(stacks);
}

static void	ft_malloc_stacks(t_stacks *stacks)
{
	stacks->a.array = malloc(sizeof(int32_t) * stacks->nums + 1);
	stacks->b.array = malloc(sizeof(int32_t) * stacks->nums + 1);
	stacks->store.key = malloc(sizeof(int32_t) * stacks->nums);
	stacks->store.value = malloc(sizeof(int32_t) * stacks->nums);
	if (!stacks->a.array || !stacks->b.array
		|| !stacks->store.key || !stacks->store.value)
		ft_cleanup_and_exit(stacks, true);
	ft_memset(stacks->a.array, 0, (stacks->nums + 1) * sizeof(int32_t));
	ft_memset(stacks->b.array, 0, (stacks->nums + 1) * sizeof(int32_t));
	ft_memset(stacks->store.key, 0, stacks->nums * sizeof(int32_t));
}

static bool	ft_check_overflow(char *str)
{
	int64_t		num;
	uint32_t	len;

	len = ft_move_like_atoi(str);
	if ((str[0] != '-' && len > 10) || (str[0] == '-' && len > 11))
		return (true);
	num = ft_atoi(str);
	if ((str[0] != '-' && num < 0) || (str[0] == '-' && num > 0))
		return (true);
	return (false);
}

static void	ft_extract_nums(t_stacks *stacks, int argc, char **argv)
{
	uint32_t	i;
	int32_t		arg;
	uint32_t	pos;

	arg = 0;
	pos = -1;
	while (++arg < argc)
	{
		pos++;
		i = 0;
		while (argv[arg][i])
		{
			if (ft_check_overflow(&argv[arg][i]))
				ft_cleanup_and_exit(stacks, true);
			if (i > 0)
				pos++;
			stacks->store.value[pos] = ft_atoi(&argv[arg][i]);
			i += ft_move_like_atoi(&argv[arg][i]);
		}
	}
	stacks->store.size = stacks->nums;
}

static void	ft_check_doubles(t_stacks *stacks)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < stacks->nums)
	{
		j = i + 1;
		while (j < stacks->nums)
		{
			if (stacks->store.value[i] == stacks->store.value[j])
				ft_cleanup_and_exit(stacks, true);
			j++;
		}
		i++;
	}
}
