/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/30 14:11:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	static t_stacks	stacks;

	if (argc == 1)
	{
		ft_printf("Usage: %s <list of integers>\n", argv[0]);
		exit(0);
	}
	stacks.nums = argc - 1;
	ft_check_input(argc, argv, &stacks.nums);
	ft_parse_input(&stacks, argc, argv);
	ft_prep_input(&stacks);
	ft_print_stacks(&stacks);
	if (ft_is_sorted(&stacks.a))
	{
		ft_printf("Everything sorted\n\n");
		ft_print_stacks(&stacks);
	}
	else if (stacks.nums <= 5)
	{
		ft_printf("Starting simple_sort\n\n");
		ft_sort_simple(&stacks);
		ft_print_stacks(&stacks);
	}
	ft_cleanup_and_exit(&stacks, false);
}
