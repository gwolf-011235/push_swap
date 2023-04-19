/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:07:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 11:49:41 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_moves	ft_return_move_num(char *string)
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
		return (UNDEFINED);
}

void	ft_checker_talks(t_data *data, t_status status)
{
	if (status == ERROR)
	{
		ft_cleanup_and_leave(data, true);
	}
	if (status == OK)
	{
		ft_printf("OK\n");
	}
	else if (status == KO)
	{
		ft_printf("KO\n");
	}
	ft_cleanup_and_leave(data, false);
}

void	ft_check_move_solution(t_data *data)
{
	char	*line;
	t_moves	move;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		move = ft_return_move_num(line);
		free(line);
		if (move == UNDEFINED)
			ft_checker_talks(data, ERROR);
		else
			ft_bust_a_move(move, data);
	}
	if (ft_is_sorted(&data->a) && data->b.size == 0)
		ft_checker_talks(data, OK);
	else
		ft_checker_talks(data, KO);
}
