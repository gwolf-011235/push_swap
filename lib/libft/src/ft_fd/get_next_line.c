/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:14:59 by gwolf             #+#    #+#             */
/*   Updated: 2023/01/21 11:24:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd.h"

static bool	ft_save_the_buf(char *temp, int rd_bts, t_buf_node *cur_node)
{
	int			offset;
	int			remain_len;
	t_buf_node	*remain;

	offset = temp - cur_node->buf + 1;
	remain_len = rd_bts - offset;
	if (!remain_len)
		return (false);
	remain = ft_lstadd_buf(&cur_node);
	if (!remain)
		return (true);
	remain->size = remain_len;
	ft_memcpy(remain->buf, cur_node->buf + offset, remain_len);
	return (false);
}

static bool	ft_search_nl(t_buf_node **head, int rd_bts)
{
	char		*temp;
	t_buf_node	*new_node;

	new_node = (*head)->tail;
	temp = ft_memchr(new_node->buf, '\n', rd_bts);
	if (temp)
	{
		new_node->has_nl = true;
		new_node->size = temp - new_node->buf + 1;
		if (new_node->size != (size_t)rd_bts)
			if (ft_save_the_buf(temp, rd_bts, new_node))
				return (true);
	}
	else
	{
		new_node->has_nl = false;
		new_node->size = rd_bts;
	}
	return (false);
}

static bool	ft_read_into_buf(int fd, t_buf_node **head, size_t *p_line_size)
{
	int			rd_bts;
	t_buf_node	*new_node;

	rd_bts = 1;
	while (rd_bts)
	{
		new_node = ft_lstadd_buf(head);
		if (!new_node)
			return (true);
		rd_bts = read(fd, new_node->buf, BUFFER_SIZE);
		if (!rd_bts)
		{
			new_node->size = 0;
			new_node->has_nl = false;
			break ;
		}
		if (ft_search_nl(head, rd_bts))
			return (true);
		*p_line_size += new_node->size;
		if (new_node->has_nl || rd_bts < BUFFER_SIZE)
			break ;
	}
	return (false);
}

static char	*ft_prep_line(t_buf_node **head, size_t	*p_line_size)
{
	char		*line;
	size_t		line_size;
	t_buf_node	*temp;

	temp = *head;
	if (temp && temp->size != 0)
	{
		line_size = *p_line_size;
		line = malloc(line_size + 1);
		if (!line)
			return (NULL);
		line[line_size] = 0;
		temp = *head;
		while (temp)
		{
			ft_memcpy(line, temp->buf, temp->size);
			line += temp->size;
			if (temp->has_nl)
				break ;
			temp = temp->next;
		}
		return (line - line_size);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_buf_node	*cluster[4096];
	char				*line;
	size_t				line_size;

	if (fd < 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (ft_lstclear_plus(&cluster[fd], true));
	if (cluster[fd] && ft_search_nl(&cluster[fd], cluster[fd]->size))
		return (ft_lstclear_plus(&cluster[fd], true));
	if (cluster[fd])
		line_size = cluster[fd]->size;
	else
		line_size = 0;
	if (!cluster[fd] || !cluster[fd]->has_nl)
		if (ft_read_into_buf(fd, &cluster[fd], &line_size))
			return (ft_lstclear_plus(&cluster[fd], true));
	line = ft_prep_line(&cluster[fd], &line_size);
	if (!line)
		return (ft_lstclear_plus(&cluster[fd], true));
	ft_lstclear_plus(&cluster[fd], false);
	return (line);
}
