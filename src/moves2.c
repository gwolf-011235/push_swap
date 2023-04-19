/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:46:52 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 10:49:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_swap(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_double_rotate(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_double_rev_rotate(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}
