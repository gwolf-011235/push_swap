/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:02:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/27 23:03:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREP_INPUT_H
# define PREP_INPUT_H

# include "push_swap.h"

void			ft_prep_input(t_data *data);
static void		ft_assign_keys(t_data *data);
static uint32_t	ft_find_next_max(t_store *store, uint32_t nums);

#endif
