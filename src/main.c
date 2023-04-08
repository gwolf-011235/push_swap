/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 07:47:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_data	data;

	if (argc == 1)
	{
		ft_printf("Usage: %s <list of integers>\n", argv[0]);
		exit(0);
	}
	else if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			argv[1] = get_next_line(fd);
			close(fd);
		}
	}
	data.nums = argc - 1;
	ft_check_input(argc, argv, &data.nums);
	ft_parse_input(&data, argc, argv);
	ft_prep_input(&data);
	ft_print_stacks(&data);
	data.div = DIV;
	ft_prep_chunks(&data);
	ft_presort_chunks(&data);
	ft_insertion_sort(&data, &data.chunks[2]);
	ft_print_moves(&data.moves);
	ft_print_stacks(&data);
	ft_cleanup_and_exit(&data, false);
	if (ft_is_sorted(&data.a))
	{
		ft_printf("Everything sorted\n\n");
	}
	else if (data.nums <= 5)
	{
		ft_printf("Starting simple_sort\n\n");
		ft_simple_sort(&data);
	}
	else
	{
		ft_insertion_sort(&data, data.chunks);
	}
	ft_print_moves(&data.moves);
	ft_print_stacks(&data);
	ft_cleanup_and_exit(&data, false);
}
