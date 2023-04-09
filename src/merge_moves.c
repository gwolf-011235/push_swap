/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:19:12 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/09 08:21:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge_dupl_moves(t_queue *moves)
{
	t_node	*yin;
	t_node	*yang;
	t_node	*remove;

	yin = ft_find_dupl_yin(moves->head, RA);
	while (yin != NULL)
	{
		yang = ft_find_dupl_yang(yin, RB);
		if (yang != NULL)
		{
			remove = yang->next;
			yang->next = remove->next;
			free(remove);
			yin->value = RR;
		}
		yin = ft_find_dupl_yin(yin->next, RA);
	}
}

t_node	*ft_find_dupl_yin(t_node *temp, uint8_t move)
{
	if (temp == NULL)
		return (NULL);
	while (temp->value != move || temp->next != NULL)
		temp = temp->next;
	if (temp->next == NULL)
		return (NULL);
	else
		return (temp);
}

t_node	*ft_find_dupl_yang(t_node *temp, uint8_t move)
{
	t_node	*remove;

	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		remove = temp->next;
		if (remove->value == move)
			break ;
		else if (remove->value == PA || remove->value == PB)
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
