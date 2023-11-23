/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:40:29 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/16 12:43:35 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	rrotate(t_tri **stack)
{
	t_tri	*end;
	t_tri	*jend;
	t_tri	*tmp;

	end = go_end(*stack);
	jend = go_end_minus_1(*stack);
	jend->head = NULL;
	tmp = *stack;
	*stack = end;
	end->head = tmp;
}

void	rra(t_tri **a)
{
	rrotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rrb(t_tri **b)
{
	rrotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rrr(t_tri **a, t_tri **b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
