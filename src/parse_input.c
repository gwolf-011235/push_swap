/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:50:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 16:57:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_input(t_stacks *stacks, int argc, char **argv)
{
	ft_malloc_stacks(stacks);
	ft_extract_nums(stacks, argc, argv);
	ft_print_stacks(stacks);
	ft_check_doubles(stacks);
}

void	ft_malloc_stacks(t_stacks *stacks)
{
	stacks->a.array = malloc(sizeof(int) * stacks->nums + 1);
	if (!stacks->a.array)
		ft_terminate();
	stacks->b.array = malloc(sizeof(int) * stacks->nums + 1);
	if (!stacks->b.array)
		ft_free_and_terminate(stacks);
	ft_memset(stacks->a.array, 0, (stacks->nums + 1) * sizeof(int));
	ft_memset(stacks->b.array, 0, (stacks->nums + 1) * sizeof(int));
}

void	ft_extract_nums(t_stacks *stacks, int argc, char **argv)
{
	uint32_t	i;
	uint32_t	pos;

	pos = stacks->nums;
	while (argc-- > 1)
	{
		pos--;
		i = 0;
		while (argv[argc][i])
		{
			if (i > 0)
				pos--;
			stacks->a.array[pos] = ft_atoi(&argv[argc][i]);
			i += ft_move_like_atoi(&argv[argc][i]);
		}
	}
	stacks->a.size = stacks->nums;
	stacks->b.size = 0;
}

void	ft_check_doubles(t_stacks *stacks)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < stacks->nums)
	{
		j = i + 1;
		while (j < stacks->nums)
		{
			if (stacks->a.array[i] == stacks->a.array[j])
				ft_free_and_terminate(stacks);
			j++;
		}
		i++;
	}
}
