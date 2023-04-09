/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 07:04:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/09 18:42:47 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "ft_fd.h"
# include "ft_print.h"

# define A 0
# define B 1
# define SUM 2

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

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"

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

//moves.c
void		ft_swap(t_stack *stack);
void		ft_push(t_stack *dst, t_stack *src);
void		ft_rotate(t_stack *stack);
void		ft_rev_rotate(t_stack *stack);

//merge_moves.c
void		ft_merge_dupl_moves(t_queue *moves);
void		ft_merge_yin_and_yang(t_queue *moves,
				uint8_t yin_mv, uint8_t yang_mv, uint8_t whole);
t_node		*ft_find_yin(t_node *temp, uint8_t yin_mv);
t_node		*ft_find_yang(t_node *temp, uint8_t yin_mv, uint8_t yang_mv,
				uint8_t whole);

//utils_print.c
void		ft_print_stacks(t_data *data);
void		ft_print_stack_stats(t_data *data);
void		ft_color_print(char *string, uint32_t num);
void		ft_print_moves(t_queue *moves);

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
uint32_t	ft_find_next_above_in_chunk(uint32_t target, t_stack *stack,
				t_chunk *chunk);
uint32_t	ft_find_next_below_in_chunk(uint32_t target, t_stack *stack,
				t_chunk *chunk);
int32_t		ft_abs(int32_t num);

//terminate.c
void		ft_terminate(void);
void		ft_cleanup_and_exit(t_data *data, bool error);

//queue.c
void		ft_init_queue(t_queue *q);
bool		ft_enqueue(t_queue *q, uint8_t value);
uint8_t		ft_dequeue(t_queue *q);

//sort_simple.c
void		ft_simple_sort(t_data *data);
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
void		ft_chunk_update_bounds(t_data *data, t_chunk *chunk);
void		ft_chunk_prep_push(t_data *data, t_chunk *chunk, t_chunk *two);
void		ft_presort_chunks(t_data *data, t_chunk *one, t_chunk *two);

//sort_insertion.c
void		ft_insertion_sort(t_data *data, t_chunk *chunk);
int32_t		ft_count_rot_top(uint32_t num, t_stack *stack);
int32_t		ft_count_rot_bot(uint32_t num, t_stack *stack);
void		ft_rot_and_push_b(uint32_t num, t_data *data, t_chunk *chunk);

//sort_next_move.c
t_next		ft_calc_next_move(t_data *data);
int32_t		ft_calc_insert_cost(uint32_t num, t_stack *stack, t_next *move);
int32_t		ft_calc_sum_cost(int32_t cost_a, int32_t cost_b);
void		ft_update_next_move(t_next *move, int32_t cost_sum, uint32_t i);

//logic.c
char		*ft_return_move_string(uint8_t move);
bool		ft_is_sorted(t_stack *stack);

//do_move.c
void		ft_bust_a_move(uint8_t move, t_data *data);
void		ft_bust_some_moves(uint8_t move, t_data *data, uint32_t repeat);

#endif
