/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/26 19:31:10 by gwolf            ###   ########.fr       */
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

//check_input.c
bool		ft_check_input(int argc, char **argv, uint32_t *count);

//parse_input.c
void		ft_parse_input(t_stacks *stacks, int argc, char **argv);

//utils_print.c
void	ft_print_stacks(t_stacks *stacks);

//utils_string.c
int		ft_move_like_atoi(char *str);

//terminate.c
void	ft_terminate(void);
void	ft_free_and_terminate(t_stacks *stacks);

#endif
