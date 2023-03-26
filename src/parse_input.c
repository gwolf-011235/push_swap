/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:50:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 15:32:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_input(t_stack *stack, int argc, char **argv)
{
	ft_malloc_stack(stack);
	ft_extract_nums(stack, argc, argv);
	ft_print_stacks(stack);
	ft_check_doubles(stack);
}

void	ft_malloc_stack(t_stack *stack)
{
	stack->a = malloc(sizeof(int) * stack->nums + 1);
	if (!stack->a)
		ft_terminate();
	stack->b = malloc(sizeof(int) * stack->nums + 1);
	if (!stack->b)
		ft_free_and_terminate(stack);
	ft_memset(stack->a, 0, (stack->nums + 1) * 4);
	ft_memset(stack->b, 0, (stack->nums + 1) * 4);
}

void	ft_extract_nums(t_stack *stack, int argc, char **argv)
{
	uint32_t	i;
	uint32_t	pos;

	pos = stack->nums;
	while (argc-- > 1)
	{
		pos--;
		i = 0;
		while (argv[argc][i])
		{
			if (i > 0)
				pos--;
			stack->a[pos] = ft_atoi(&argv[argc][i]);
			i += ft_move_like_atoi(&argv[argc][i]);
		}
	}
	stack->a_count = stack->nums;
	stack->b_count = 0;
}

void	ft_check_doubles(t_stack *stack)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < stack->nums)
	{
		j = i + 1;
		while (j < stack->nums)
		{
			if (stack->a[i] == stack->a[j])
				ft_free_and_terminate(stack);
			j++;
		}
		i++;
	}
}
