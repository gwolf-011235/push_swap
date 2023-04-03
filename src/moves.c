/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:37:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/03 22:09:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	uint32_t	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
}

void	ft_push(t_stack *dst, t_stack *src)
{
	if (src->size == 0)
		return ;
	ft_memmove(dst->array + 1, dst->array, dst->size * sizeof(int32_t));
	dst->array[0] = src->array[0];
	ft_memmove(src->array, src->array + 1, src->size * sizeof(int32_t));
	dst->size++;
	src->size--;
}

void	ft_rotate(t_stack *stack)
{
	uint32_t	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[0];
	ft_memmove(stack->array, stack->array + 1, stack->size * sizeof(int32_t));
	stack->array[stack->size - 1] = temp;
}

void	ft_rev_rotate(t_stack *stack)
{
	uint32_t	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[stack->size - 1];
	ft_memmove(stack->array + 1, stack->array, stack->size * sizeof(int32_t));
	stack->array[0] = temp;
}
