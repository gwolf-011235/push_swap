/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_with_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:49:07 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:17:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_data	data;
	static bool		file_opened;

	if (argc == 1)
	{
		ft_printf("Usage: %s <list of integers>\n", argv[0]);
		exit(0);
	}
	else if (argc == 2)
		file_opened = ft_try_open(argv);
	data.nums = argc - 1;
	ft_check_input(argc, argv, &data.nums);
	ft_parse_input(&data, argc, argv);
	ft_prep_input(&data);
	if (ft_is_sorted(&data.a))
	{
		ft_printf("Everything sorted\n\n");
	}
	else if (data.nums <= 5)
	{
		ft_printf("Starting simple_sort\n\n");
		ft_sort_simple(&data);
	}
	else
	{
		ft_printf("Starting complex_sort\n\n");
		ft_sort_complex(&data);
	}
	if (file_opened)
		free(argv[1]);
	//if (!ft_is_sorted(&data.a))
		//ft_cleanup_and_leave(&data, true);
	ft_print_stacks(&data);
	ft_merge_dupl_moves(&data.moves);
	ft_print_moves_queue(&data.moves);
	ft_cleanup_and_leave(&data, false);
}
