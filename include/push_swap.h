/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/28 19:52:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_print.h"

# define A 0
# define B 1
# define BOTH 2

typedef struct	s_stack {
	uint32_t	size;
	uint32_t	*array;
}	t_stack;

typedef struct	s_store {
	uint32_t	size;
	uint32_t	*key;
	int32_t		*value;
}	t_store;

typedef struct	s_node {
	char			*string;
	struct s_node	*next;
}	t_node;

typedef struct s_queue {
	t_node	*head;
	t_node	*tail;
}	t_queue;

typedef struct	s_stacks {
	uint32_t	nums;
	t_stack		a;
	t_stack		b;
	t_store		store;
	t_queue		moves;
}	t_stacks;

//check_input.c
bool	ft_check_input(int argc, char **argv, uint32_t *count);

//parse_input.c
void	ft_parse_input(t_stacks *stacks, int argc, char **argv);

//prep_input.c
void	ft_prep_input(t_stacks *stacks);

//ops.c
void	ft_swap(t_stacks *stacks, uint8_t option);
void	ft_push(t_stacks *stacks, uint8_t option);
void	ft_rotate(t_stacks *stacks, uint8_t option);
void	ft_rev_rotate(t_stacks *stacks, uint8_t option);

//utils_print.c
void	ft_print_stacks(t_stacks *stacks);

//utils_string.c
int		ft_move_like_atoi(char *str);

//terminate.c
void	ft_terminate(void);
void	ft_free_and_terminate(t_stacks *stacks);

//queue.c
void	ft_init_queue(t_queue *q);
bool	ft_enqueue(t_queue *q, char *string);
char	*ft_dequeue(t_queue *q);

#endif
