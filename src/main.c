/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 17:40:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_try_open(char **argv)
{
	int		fd;
	char	*temp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	temp = get_next_line(fd);
	while (temp)
	{
		argv[1] = temp;
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(argv[1]);
	}
	close(fd);
	return (true);
}

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
		ft_simple_sort(&data);
	}
	else
	{
		ft_printf("Starting complex_sort\n\n");
		ft_sort_complex(&data);
	}
	//ft_print_moves(&data.moves);
	if (file_opened)
		free(argv[1]);
	ft_cleanup_and_exit(&data, false);
}
