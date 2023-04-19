/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:19:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 11:51:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

//libft
# include "ft_fd.h"

// push_swap
# include "push_swap.h"

//	typedef
typedef enum e_status {OK, KO, ERROR}	t_status;

// checker_utils.c
void	ft_check_move_solution(t_data *data);
void	ft_checker_talks(t_data *data, t_status status);
t_moves	ft_return_move_num(char *string);

#endif