/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 12:22:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//lib c
# include <stdint.h>
# include <stdbool.h>

// libft
# include "ft_print.h"

//macros
# define A 0
# define B 1
# define SUM 2

//typedef
typedef enum e_moves {
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	UNDEFINED = 255
}	t_moves;

typedef enum e_mode {
	PRINT,
	ENQUEUE,
	SILENT
}	t_mode;

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
	uint8_t			value;
	struct s_node	*next;
}	t_node;

typedef struct s_queue {
	t_node	*head;
	t_node	*tail;
}	t_queue;

typedef struct s_chunk {
	uint32_t	size;
	uint32_t	min;
	uint32_t	max;
	uint32_t	pushed;
	uint32_t	bounds[2];
}	t_chunk;

typedef struct s_data {
	uint32_t	nums;
	uint32_t	div;
	t_stack		a;
	t_stack		b;
	t_store		store;
	t_queue		moves;
	t_chunk		*chunks;
	t_mode		mode;
}	t_data;

typedef struct s_next {
	int32_t	index;
	int32_t	cost;
	int32_t	temp;
	int32_t	target;
	bool	top;
}	t_next;

//check_input.c
bool		ft_check_input(int argc, char **argv, uint32_t *count);

//parse_input.c
void		ft_parse_input(t_data *data, int argc, char **argv);

//prep_input.c
void		ft_prep_input(t_data *data);

//moves_exec.c
void		ft_bust_a_move(t_moves move, t_data *data);
void		ft_bust_some_moves(t_moves move, t_data *data, uint32_t repeat);
void		ft_handle_move(t_moves move, t_data *data);

//moves.c
void		ft_swap(t_stack *stack);
void		ft_push(t_stack *dst, t_stack *src);
void		ft_rotate(t_stack *stack);
void		ft_rev_rotate(t_stack *stack);

//moves2.c
void		ft_double_swap(t_stack *a, t_stack *b);
void		ft_double_rotate(t_stack *a, t_stack *b);
void		ft_double_rev_rotate(t_stack *a, t_stack *b);

//merge_moves.c
void		ft_merge_dupl_moves(t_queue *moves);
void		ft_merge_yin_and_yang(t_queue *moves,
				uint8_t yin_mv, uint8_t yang_mv, uint8_t whole);
t_node		*ft_find_yin(t_node *temp, uint8_t yin_mv);
t_node		*ft_find_yang(t_node *temp, uint8_t yin_mv, uint8_t yang_mv,
				uint8_t whole);
//queue.c
void		ft_init_queue(t_queue *q);
bool		ft_enqueue(t_queue *q, uint8_t value);
uint8_t		ft_dequeue(t_queue *q);
void		ft_kill_queue(t_queue *q);

//sort_simple.c
void		ft_sort_simple(t_data *data);
void		ft_sort_two(t_data *data);
void		ft_sort_three(t_data *data);
void		ft_sort_four(t_data *data);
void		ft_sort_five(t_data *data);

//sort_complex.c
void		ft_sort_complex(t_data *data);
void		ft_exec_next_move(t_data *data, t_next *move);

//sort_chunks.c
void		ft_prep_chunks(t_data *data);
bool		ft_is_elem_of_chunk(uint32_t num, t_chunk *chunk);
void		ft_quick_chunk_sort(t_data *data, t_chunk *one, t_chunk *two);

//sort_next_move.c
t_next		ft_calc_next_move(t_data *data);
int32_t		ft_calc_insert_cost(uint32_t num, t_stack *stack, t_next *move);
int32_t		ft_calc_sum_cost(int32_t cost_a, int32_t cost_b);
void		ft_update_next_move(t_next *move, int32_t cost_sum, uint32_t i);

//print_moves.c
void		ft_print_move_string(t_moves move);
void		ft_print_moves_queue(t_queue *moves);

//utils_string.c
int			ft_move_like_atoi(char *str);
bool		ft_check_overflow(char *str);

//utils_sort.c
uint32_t	ft_search_from_top(t_stack *stack, uint32_t num);
bool		ft_rotate_to_top(uint8_t name, t_data *data, uint32_t num);
bool		ft_rotate_to_bottom(uint8_t name, t_data *data, uint32_t num);
uint32_t	ft_find_higher_neighbor(uint32_t target, t_stack *stack);
uint32_t	ft_find_lower_neighbor(uint32_t target, t_stack *stack);

//utils_sort2.c
bool		ft_is_sorted(t_stack *stack);
int32_t		ft_count_rot_top(uint32_t num, t_stack *stack);
int32_t		ft_count_rot_bot(uint32_t num, t_stack *stack);

//terminate.c
void		ft_terminate(void);
void		ft_cleanup_and_leave(t_data *data, bool error);

//print_stacks.c
void		ft_print_stacks(t_data *data);

//try_open.c
bool		ft_try_open(char **argv);

#endif
