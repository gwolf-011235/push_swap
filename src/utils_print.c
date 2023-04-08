/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf < gwolf@student.42vienna.com >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:05:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/04/08 08:36:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_color_print(char *string, uint32_t num)
{
	if (num <= 33)
		ft_printf(GREEN);
	else if (num <= 66)
		ft_printf(YELLOW);
	else
		ft_printf(RED);
	ft_printf(string, num);
	ft_printf(RESET);
}

void	ft_print_stacks(t_data *data)
{
	uint32_t	i;
	int64_t		temp_a;
	int64_t		temp_b;

	i = 0;
	temp_a = data->a.size;
	temp_b = data->b.size;
	ft_printf("The stacks are\n\n");
	while (temp_a > 0 || temp_b > 0)
	{
		if (temp_a > 0 && temp_b > 0)
		{
			ft_color_print("\t%5d", data->a.array[i]);
			ft_color_print("\t%5d", data->b.array[i]);
		}
		else if (temp_a > 0)
			ft_color_print("\t%5d", data->a.array[i]);
		else if (temp_b > 0)
			ft_color_print("\t\t%5d", data->b.array[i]);
		temp_a--;
		temp_b--;
		ft_printf("\n");
		i++;
	}
	ft_printf("\t_____\t_____\n\t  a  \t  b\n\n");
	ft_printf("Sum of integers: %d\n", data->nums);
	ft_printf("Integers in stack a: %d\n", data->a.size);
	ft_printf("Integers in stack b: %d\n\n", data->b.size);
}

void	ft_print_moves(t_queue *moves)
{
	char	*string;

	if (moves->head == NULL)
		return ;
	while (moves->head)
	{
		string = ft_dequeue(moves);
		ft_printf("%s", string);
	}
}
