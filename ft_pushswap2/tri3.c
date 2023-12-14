/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:16:35 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/14 11:52:35 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	push_low_half(t_tri **stack_a, t_tri **stack_b)
{
	int	stack_t;
	int	pushed;
	int	i;

	stack_t = taille(*stack_a);
	pushed = 0;
	i = 0;
	while (i < stack_t && pushed < stack_t / 2)
	{
		if ((*stack_a)->index <= stack_t / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
}

void	push_big_half(t_tri **stacka, t_tri **stackb)
{
	int	stack_t;
	int	pushed;

	stack_t = taille(*stacka);
	pushed = 0;
	while (stack_t - pushed > 3)
	{
		pb(stacka, stackb);
		pushed++;
	}
}

int	find_lowest(t_tri **stack)
{
	t_tri	*stacka;
	int		lowest_index;
	int		lowest_position;

	stacka = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_position = stacka->position;
	while (stacka)
	{
		if (stacka->index < lowest_index)
		{
			lowest_index = stacka->index;
			lowest_position = stacka->position;
		}
		stacka = stacka->head;
	}
	return (lowest_position);
}

void	replacing(t_tri **stack_a)
{
	int	low_nbr;
	int	taille_s;

	taille_s = taille(*stack_a);
	low_nbr = find_lowest(stack_a);
	if (low_nbr > taille_s / 2)
	{
		while (low_nbr < taille_s)
		{
			rra(stack_a);
			low_nbr++;
		}
	}
	else
	{
		while (low_nbr > 0)
		{
			ra(stack_a);
			low_nbr--;
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
