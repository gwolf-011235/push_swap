/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/01 14:06:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_print.h"

# define A 0
# define B 1
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_stack {
	uint32_t	size;
	uint32_t	*array;
}	t_stack;

typedef struct s_store {
	uint32_t	size;
	uint32_t	*key;
	int32_t		*value;
}	t_store;

typedef struct s_node {
	char			*string;
	struct s_node	*next;
}	t_node;

typedef struct s_queue {
	t_node	*head;
	t_node	*tail;
}	t_queue;

typedef struct s_stacks {
	uint32_t	nums;
	uint32_t	cur_half;
	uint32_t	divide_count;
	t_stack		a;
	t_stack		b;
	t_store		store;
	t_queue		moves;
}	t_stacks;

//check_input.c
bool		ft_check_input(int argc, char **argv, uint32_t *count);

//parse_input.c
void		ft_parse_input(t_stacks *stacks, int argc, char **argv);

//prep_input.c
void		ft_prep_input(t_stacks *stacks);

//moves.c
void		ft_swap(t_stack *stack);
void		ft_push(t_stack *dst, t_stack *src);
void		ft_rotate(t_stack *stack);
void		ft_rev_rotate(t_stack *stack);

//utils_print.c
void		ft_print_stacks(t_stacks *stacks);
void		ft_print_moves(t_queue *moves);

//utils_string.c
int			ft_move_like_atoi(char *str);

//utils_sort.c
uint32_t	ft_search_from_top(t_stack *stack, uint32_t num);
bool		ft_rotate_to_top(uint8_t name, t_stacks *stacks, uint32_t num);

//terminate.c
void		ft_terminate(void);
void		ft_cleanup_and_exit(t_stacks *stacks, bool error);

//queue.c
void		ft_init_queue(t_queue *q);
bool		ft_enqueue(t_queue *q, char *string);
char		*ft_dequeue(t_queue *q);

//sort_simple.c
void		ft_simple_sort(t_stacks *stacks);
void		ft_sort_two(t_stacks *stacks);
void		ft_sort_three(t_stacks *stacks);
void		ft_sort_four(t_stacks *stacks);
void		ft_sort_five(t_stacks *stacks);

//sort_quick.c
void		ft_quick_sort(t_stacks *stacks);
void		ft_split_a(t_stacks *stacks);

//logic.c
char		*ft_return_move_string(uint8_t move);
bool		ft_is_sorted(t_stack *stack);

//do_move.c
void		ft_bust_a_move(uint8_t move, t_stacks *stacks);
void		ft_bust_some_moves(uint8_t move, t_stacks *stacks, uint32_t repeat);

#endif
