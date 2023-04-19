/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:19:12 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 11:28:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_moves(t_queue *moves)
{
	t_moves	move;

	if (moves->head == NULL)
		return ;
	while (moves->head)
	{
		move = ft_dequeue(moves);
		if (move == UNDEFINED)
			return ;
		ft_print_move_string(move);
	}
}

void	ft_merge_dupl_moves(t_queue *moves)
{
	ft_merge_yin_and_yang(moves, RA, RB, RR);
	ft_merge_yin_and_yang(moves, RB, RA, RR);
	ft_merge_yin_and_yang(moves, RRA, RRB, RRR);
	ft_merge_yin_and_yang(moves, RRB, RRA, RRR);
}

void	ft_merge_yin_and_yang(t_queue *moves,
			uint8_t yin_mv, uint8_t yang_mv, uint8_t whole)
{
	t_node	*yin;
	t_node	*yang;
	t_node	*remove;

	yin = ft_find_yin(moves->head, yin_mv);
	while (yin != NULL)
	{
		yang = ft_find_yang(yin, yin_mv, yang_mv, whole);
		if (yang != NULL)
		{
			remove = yang->next;
			yang->next = remove->next;
			free(remove);
			yin->value = whole;
		}
		yin = ft_find_yin(yin->next, yin_mv);
	}
}

t_node	*ft_find_yin(t_node *temp, uint8_t yin_mv)
{
	if (temp == NULL)
		return (NULL);
	while (temp->value != yin_mv && temp->next != NULL)
		temp = temp->next;
	if (temp->next == NULL)
		return (NULL);
	else
		return (temp);
}

t_node	*ft_find_yang(t_node *temp, uint8_t yin_mv, uint8_t yang_mv,
			uint8_t whole)
{
	t_node	*remove;

	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		remove = temp->next;
		if (remove->value == yang_mv)
			break ;
		else if ((remove->value != yin_mv && remove->value != yang_mv
				&& remove->value != whole) || remove->next == NULL)
		{
			remove = NULL;
			break ;
		}
		temp = temp->next;
	}
	if (remove == NULL)
		return (NULL);
	else
		return (temp);
}
