/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:27:01 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 17:47:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include "push_swap.h"

void		ft_parse_input(t_data *data, int argc, char **argv);
static void	ft_set_div(t_data *data);
static void	ft_malloc_all_the_things(t_data *data);
static void	ft_extract_nums(t_data *data, int argc, char **argv);
static void	ft_check_doubles(t_data *data);

#endif
