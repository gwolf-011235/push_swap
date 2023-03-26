/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 15:32:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_print.h"

typedef struct	s_stack {
	uint32_t	nums;
	int			*a;
	uint32_t	a_count;
	int			*b;
	uint32_t	b_count;
}	t_stack;

bool	ft_check_input(int argc, char **argv, uint32_t *count);
bool	ft_is_valid_num(char *str);
int		ft_move_like_atoi(char *str);

void	ft_parse_input(t_stack *stack, int argc, char **argv);
void	ft_malloc_stack(t_stack *stack);
void	ft_extract_nums(t_stack *stack, int argc, char **argv);
void	ft_check_doubles(t_stack *stack);

void	ft_print_stacks(t_stack *stack);


void	ft_terminate(void);
void	ft_free_and_terminate(t_stack *stack);

#endif
