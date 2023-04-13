/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:31:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/13 07:34:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STACKS_H
# define PRINT_STACKS_H

# include "push_swap.h"

void		ft_print_stacks(t_data *data);
static void	ft_print_stats(t_data *data);
static void	ft_color_print(char *string, uint32_t num);

#endif