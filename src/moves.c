/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:37:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/29 01:03:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bust_a_move(uint8_t move, t_stacks *stacks)
{
	if (move == SA)
		ft_swap(&stacks->a);
	else if (move == SB)
		ft_swap(&stacks->b);
	else if (move == PA)
		ft_push(&stacks->a, &stacks->b);
	else if (move == PB)
		ft_push(&stacks->b, &stacks->a);
	else if (move == RA)
		ft_rotate(&stacks->a);
	else if (move == RB)
		ft_rotate(&stacks->b);
	else if (move == RRA)
		ft_rev_rotate(&stacks->a);
	else if (move == RRB)
		ft_rev_rotate(&stacks->b);
	if (!ft_enqueue(&stacks->moves, ft_ret_move_string(move)))
		ft_cleanup_and_exit(stacks, true);
}

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
	if (src->size < 0)
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

	temp = stack->array[0];
	ft_memmove(stack->array, stack->array + 1, stack->size * sizeof(int32_t));
	stack->array[stack->size - 1] = temp;
}

void	ft_rev_rotate(t_stack *stack)
{
	uint32_t	temp;

	temp = stack->array[stack->size - 1];
	ft_memmove(stack->array + 1, stack->array, stack->size * sizeof(int32_t));
	stack->array[0] = temp;

}
