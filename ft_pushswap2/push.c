/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:41:16 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/16 12:41:32 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	push(t_tri **stacka, t_tri **stackb)
{
	t_tri	*tmp;

	tmp = (*stacka)->head;
	(*stacka)->head = *stackb;
	*stackb = *stacka;
	*stacka = tmp;
}

void	pa(t_tri **pa, t_tri **pb)
{
	push(pb, pa);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_tri **pa, t_tri **pb)
{
	push(pa, pb);
	ft_putstr_fd("pb\n", 1);
}
