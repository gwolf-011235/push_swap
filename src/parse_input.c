/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:50:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/15 14:30:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

void	ft_parse_input(t_data *data, int argc, char **argv)
{
	ft_set_div(data);
	ft_malloc_all_the_things(data);
	ft_extract_nums(data, argc, argv);
	ft_check_doubles(data);
}

static void	ft_set_div(t_data *data)
{
	if (data->nums <= 10)
		data->div = 1;
	else if (data->nums <= 40)
		data->div = 2;
	else if (data->nums <= 100)
		data->div = 3;
	else if (data->nums <= 160)
		data->div = 4;
	else if (data->nums <= 250)
		data->div = 5;
	else if (data->nums <= 360)
		data->div = 6;
	else if (data->nums <= 500)
		data->div = 7;
	else
		data->div = 8;
}

static void	ft_malloc_all_the_things(t_data *data)
{
	data->a.array = malloc((data->nums + 1) * sizeof(int32_t));
	data->b.array = malloc((data->nums + 1) * sizeof(int32_t));
	data->store.key = malloc(data->nums * sizeof(int32_t));
	data->store.value = malloc(data->nums * sizeof(int32_t));
	data->chunks = malloc(data->div * sizeof(t_chunk));
	if (!data->a.array || !data->b.array
		|| !data->store.key || !data->store.value
		|| !data->chunks)
		ft_cleanup_and_leave(data, true);
	ft_memset(data->a.array, 0, (data->nums + 1) * sizeof(int32_t));
	ft_memset(data->b.array, 0, (data->nums + 1) * sizeof(int32_t));
	ft_memset(data->store.key, 0, data->nums * sizeof(int32_t));
}

static void	ft_extract_nums(t_data *data, int argc, char **argv)
{
	uint32_t	i;
	int32_t		arg;
	uint32_t	pos;

	arg = 0;
	pos = -1;
	while (++arg < argc)
	{
		pos++;
		i = 0;
		while (argv[arg][i])
		{
			if (ft_check_overflow(&argv[arg][i]))
				ft_cleanup_and_leave(data, true);
			if (i > 0)
				pos++;
			data->store.value[pos] = ft_atoi(&argv[arg][i]);
			i += ft_move_like_atoi(&argv[arg][i]);
		}
	}
	data->store.size = data->nums;
}

static void	ft_check_doubles(t_data *data)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < data->nums)
	{
		j = i + 1;
		while (j < data->nums)
		{
			if (data->store.value[i] == data->store.value[j])
				ft_cleanup_and_leave(data, true);
			j++;
		}
		i++;
	}
}
