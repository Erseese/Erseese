/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:37:59 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/16 12:38:53 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	rotate(t_tri **stack)
{
	t_tri	*tmp;
	t_tri	*end;

	end = go_end(*stack);
	tmp = (*stack)->head;
	end->head = *stack;
	*stack = tmp;
	end->head->head = NULL;
}

void	ra(t_tri **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_tri **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_tri **a, t_tri **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
