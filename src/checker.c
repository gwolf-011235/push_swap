/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:06:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/12 17:42:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	ft_return_move_num(char *string)
{
	if (ft_strncmp("sa\n", string, 4) == 0)
		return (SA);
	else if (ft_strncmp("sb\n", string, 4) == 0)
		return (SB);
	else if (ft_strncmp("ss\n", string, 4) == 0)
		return (SS);
	else if (ft_strncmp("pa\n", string, 4) == 0)
		return (PA);
	else if (ft_strncmp("pb\n", string, 4) == 0)
		return (PB);
	else if (ft_strncmp("ra\n", string, 4) == 0)
		return (RA);
	else if (ft_strncmp("rb\n", string, 4) == 0)
		return (RB);
	else if (ft_strncmp("rr\n", string, 4) == 0)
		return (RR);
	else if (ft_strncmp("rra\n", string, 5) == 0)
		return (RRA);
	else if (ft_strncmp("rrb\n", string, 5) == 0)
		return (RRB);
	else if (ft_strncmp("rrr\n", string, 5) == 0)
		return (RRR);
	else
		return (255);
}

void	ft_checker_talks(t_data *data, bool cool)
{
	if (cool)
	{
		ft_printf("OK\n");
	}
	else
	{
		ft_printf("KO\n");
	}
	ft_cleanup_and_leave(data, false);
}

void	ft_check_before(t_data *data)
{
	char	*input;

	if (ft_is_sorted(&data->a))
	{
		input = get_next_line(0);
		if (input != NULL)
		{
			free(input);
			ft_checker_talks(data, false);
		}
		else
			ft_checker_talks(data, true);
	}
}

void	ft_check_after(t_data *data)
{
	char	*input;
	uint8_t	move;

	input = ft_strdup("start");
	while (input)
	{
		free(input);
		input = get_next_line(0);
		if (input == NULL)
			break ;
		move = ft_return_move_num(input);
		ft_bust_a_move(move, data);
	}
	if (ft_is_sorted(&data->a))
		ft_checker_talks(data, true);
	else
		ft_checker_talks(data, false);
}

int	main(int argc, char *argv[])
{
	static t_data	data;

	if (argc == 1)
		exit(0);
	data.nums = argc - 1;
	ft_check_input(argc, argv, &data.nums);
	ft_parse_input(&data, argc, argv);
	ft_prep_input(&data);
	ft_check_before(&data);
	ft_check_after(&data);
}
