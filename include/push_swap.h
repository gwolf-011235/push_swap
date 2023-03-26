/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 16:56:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_print.h"

typedef struct	s_stack {
	uint32_t	size;
	int			*array;
}	t_stack;

typedef struct	s_stacks {
	uint32_t	nums;
	t_stack		a;
	t_stack		b;
}	t_stacks;

bool	ft_check_input(int argc, char **argv, uint32_t *count);
bool	ft_is_valid_num(char *str);
int		ft_move_like_atoi(char *str);

void	ft_parse_input(t_stacks *stacks, int argc, char **argv);
void	ft_malloc_stacks(t_stacks *stacks);
void	ft_extract_nums(t_stacks *stacks, int argc, char **argv);
void	ft_check_doubles(t_stacks *stacks);

void	ft_print_stacks(t_stacks *stacks);


void	ft_terminate(void);
void	ft_free_and_terminate(t_stacks *stacks);

#endif
