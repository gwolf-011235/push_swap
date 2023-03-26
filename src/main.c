/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 16:50:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	t_stacks stacks;

	if (argc == 1)
	{
		ft_printf("Usage: %s <list of integers>\n", argv[0]);
		exit(0);
	}
	stacks.nums = argc - 1;
	ft_check_input(argc, argv, &stacks.nums);
	ft_parse_input(&stacks, argc, argv);
}
