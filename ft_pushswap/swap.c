/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:39:17 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 18:27:23 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	swap(t_tri *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->head->content;
	stack->head->content = tmp;
	tmp = stack->index;
	stack->index = stack->head->index;
	stack->head->index = tmp;
}

void	sa(t_tri **a)
{
	swap(*a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_tri **b)
{
	swap(*b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_tri **a, t_tri **b)
{
	swap(*a);
	swap(*b);
	ft_putstr_fd("ss\n", 1);
}
