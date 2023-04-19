/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_typedef.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:13:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 11:15:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPEDEF_H
# define PUSH_SWAP_TYPEDEF_H

# include <stdint.h>
# include <stdbool.h>

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

#endif