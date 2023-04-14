/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:19:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/14 17:17:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

//libft
# include "ft_fd.h"

// push_swap
# include "push_swap.h"

//	types
typedef enum e_status {OK, KO, ERROR}	t_status;

// checker_utils.c
void	ft_checker_talks(t_data *data, t_status status);
void	ft_copy_the_move(uint8_t move, t_data *data);
uint8_t	ft_return_move_num(char *string);
char	*ft_buffer_next_line(char buffer[5]);
void	ft_check_move_solution(t_data *data);

#endif