/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:16:35 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/16 13:38:23 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	push_all_save_three(t_tri **stack_a, t_tri **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = taille(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

int	get_lowest_index_position(t_tri **stack)
{
	t_tri	*tmp;
	int		lowest_index;
	int		lowest_position;

	tmp = *stack;
	lowest_index = 2147483647;
	get_position(stack);
	lowest_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->head;
	}
	return (lowest_position);
}

void	shift_tri(t_tri **stack_a)
{
	int	lowest_position;
	int	stack_size;

	stack_size = taille(*stack_a);
	lowest_position = get_lowest_index_position(stack_a);
	if (lowest_position > stack_size / 2)
	{
		while (lowest_position < stack_size)
		{
			rra(stack_a);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			ra(stack_a);
			lowest_position--;
		}
	}
}

void	tritrois(t_tri **stack)
{
	t_tri	*tmp;
	int		max;
	int		min;

	tmp = *stack;
	max = -1;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->head;
	}
	if ((*stack)->index == max)
		ra(stack);
	else if ((*stack)->head->index == max)
		rra(stack);
	if ((*stack)->index > (*stack)->head->index)
		sa(stack);
}
