/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/14 16:49:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_data	data;

	if (argc == 1)
		exit(0);
	data.nums = argc - 1;
	if (!ft_check_input(argc, argv, &data.nums))
		ft_cleanup_and_leave(&data, false);
	ft_parse_input(&data, argc, argv);
	ft_prep_input(&data);
	if (ft_is_sorted(&data.a))
	{
		ft_cleanup_and_leave(&data, false);
	}
	else if (data.nums <= 5)
	{
		ft_simple_sort(&data);
	}
	else
	{
		ft_sort_complex(&data);
	}
	ft_merge_dupl_moves(&data.moves);
	ft_print_moves(&data.moves);
	ft_cleanup_and_leave(&data, false);
}
