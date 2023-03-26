/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:50:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 10:14:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	uint32_t	pos;

	ft_malloc_stack(stack);
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
	ft_print_stacks(stack);


}

void	ft_malloc_stack(t_stack *stack)
{
	stack->a = malloc(sizeof(int) * stack->nums + 1);
	if (!stack->a)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	stack->b = malloc(sizeof(int) * stack->nums + 1);
	if (!stack->b)
	{
		free(stack->a);
		write(1, "Error\n", 6);
		exit(1);
	}
	ft_memset(stack->a, 0, (stack->nums + 1) * 4);
	ft_memset(stack->b, 0, (stack->nums + 1) * 4);
}
