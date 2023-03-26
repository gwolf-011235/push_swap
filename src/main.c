/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 10:47:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	t_stack stack;

	if (argc == 1)
	{
		ft_printf("Usage: %s <list of integers>\n", argv[0]);
		exit(0);
	}
	stack.nums = argc - 1;
	ft_check_input(argc, argv, &stack.nums);
	ft_parse_input(&stack, argc, argv);
}
