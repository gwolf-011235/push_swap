/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:06:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/14 15:46:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	main(int argc, char *argv[])
{
	static t_data	data;

	if (argc == 1)
		exit(0);
	data.nums = argc - 1;
	ft_check_input(argc, argv, &data.nums);
	ft_parse_input(&data, argc, argv);
	ft_prep_input(&data);
	ft_check_move_solution(&data);
}
