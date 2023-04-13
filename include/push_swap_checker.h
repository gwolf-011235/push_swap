/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:19:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/13 07:21:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

// libft
# include "ft_fd.h"
# include "ft_print.h"

// push_swap
# include "push_swap_typedef.h"
# include "push_swap_macros.h"

// checker_utils.c
void	ft_checker_talks(t_data *data, bool cool);
void	ft_copy_the_move(uint8_t move, t_data *data);
uint8_t	ft_return_move_num(char *string);
void	ft_checker_talks(t_data *data, bool cool);
void	ft_check_move_solution(t_data *data);

#endif