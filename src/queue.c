/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:45:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:08:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_queue(t_queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

bool	ft_enqueue(t_queue *q, uint8_t	value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (false);
	newnode->value = value;
	newnode->next = NULL;
	if (q->tail != NULL)
		q->tail->next = newnode;
	q->tail = newnode;
	if (q->head == NULL)
		q->head = newnode;
	return (true);
}

uint8_t	ft_dequeue(t_queue *q)
{
	t_node	*tmp;
	uint8_t	value;

	if (q->head == NULL)
		return (255);
	tmp = q->head;
	value = tmp->value;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	return (value);
}

void	ft_kill_queue(t_queue *q)
{
	t_node	*tmp;

	while (q->head)
	{
		tmp = q->head;
		q->head = q->head->next;
		free(tmp);
	}
	q->tail = NULL;
}
