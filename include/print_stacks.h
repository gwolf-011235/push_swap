/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:31:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/19 11:54:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STACKS_H
# define PRINT_STACKS_H

# include "push_swap.h"

//colors
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"

//print_stacks.c
void		ft_print_stacks(t_data *data);
static void	ft_print_stats(t_data *data);
static void	ft_color_print(char *string, uint32_t num);

#endif