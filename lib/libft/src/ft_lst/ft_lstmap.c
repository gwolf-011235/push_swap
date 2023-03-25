/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:59:05 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:03:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

static t_list	*create(t_list *lst, void *(*f)(void *))
{
	t_list	*head;
	void	*ptr;

	ptr = f(lst->content);
	head = ft_lstnew(ptr);
	if (!head)
	{
		free(ptr);
		return (NULL);
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;
	void	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	head = create(lst, f);
	if (!head)
		return (NULL);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		ptr = f(lst->content);
		ft_lstadd_back(&head, ft_lstnew(ptr));
		if (temp->next == NULL)
		{
			ft_lstclear(&head, del);
			free(ptr);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (head);
}
