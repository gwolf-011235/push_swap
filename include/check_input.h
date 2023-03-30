/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:29:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/03/30 13:29:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

# include "push_swap.h"

bool		ft_check_input(int argc, char **argv, uint32_t *nums);
static bool	ft_is_valid_num(char *str);

#endif
