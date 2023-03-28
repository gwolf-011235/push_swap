/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:45:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/28 19:52:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_queue(t_queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

bool	ft_enqueue(t_queue *q, char *string)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (false);
	newnode->string = string;
	newnode->next = NULL;
	if (q->tail != NULL)
		q->tail->next = newnode;
	q->tail = newnode;
	if (q->head == NULL)
		q->head = newnode;
	return (true);
}

char	*ft_dequeue(t_queue *q)
{
	t_node	*tmp;
	char	*string;

	if (q->head == NULL)
		return (NULL);
	tmp = q->head;
	string = tmp->string;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	return (string);
}
