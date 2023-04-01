/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:53:05 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/01 12:08:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_stacks *stacks)
{
	stacks->cur_half = stacks->nums / 2;
	stacks->divide_count = 1;

}

void	ft_split_stack(t_stacks *stacks)