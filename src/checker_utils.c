/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:07:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/14 15:54:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	ft_copy_the_move(uint8_t move, t_data *data)
{
	if (move == SA)
		ft_swap(&data->a);
	else if (move == SB)
		ft_swap(&data->b);
	else if (move == PA)
		ft_push(&data->a, &data->b);
	else if (move == PB)
		ft_push(&data->b, &data->a);
	else if (move == RA)
		ft_rotate(&data->a);
	else if (move == RB)
		ft_rotate(&data->b);
	else if (move == RRA)
		ft_rev_rotate(&data->a);
	else if (move == RRB)
		ft_rev_rotate(&data->b);
	else if (move == 255)
		ft_checker_talks(data, false);
}

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

char	*ft_buffer_next_line(char buffer[5])
{
	int32_t	read_count;
	int32_t	offset;

	ft_memset(buffer, 0, 4);
	read_count = read(0, buffer, 1);
	if (read_count == 0)
		return (NULL);
	while (read_count < 5)
	{
		if (read_count == -1)
			return (NULL);
		offset = read_count;
		if (ft_memchr(buffer, '\n', 4))
			return (buffer);
		read_count += read(0, buffer + offset, 1);
	}
	return (NULL);
}

void	ft_check_move_solution(t_data *data)
{
	char	buffer[5];
	uint8_t	move;

	buffer[4] = '\0';
	while (1)
	{
		if (ft_buffer_next_line(buffer) == NULL)
			break ;
		move = ft_return_move_num(buffer);
		ft_copy_the_move(move, data);
	}
	if (ft_is_sorted(&data->a))
		ft_checker_talks(data, true);
	else
		ft_checker_talks(data, false);
}
