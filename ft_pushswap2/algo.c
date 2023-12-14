/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:23:01 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/14 12:06:55 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	rotaboth(t_tri **stacka, t_tri **stackb, t_tri *tmp)
{
	while (tmp->couta > 0 && tmp->coutb > 0)
	{
		tmp->couta--;
		tmp->coutb--;
		rr(stacka, stackb);
	}
}

void	rotastacka(t_tri **stacka, int *couta)
{
	while (*couta)
	{
		if (*couta > 0)
		{
			ra(stacka);
			(*couta)--;
		}
		else if (*couta < 0)
		{
			rra(stacka);
			(*couta)++;
		}
	}
}

void	rotastackb(t_tri **stackb, int *coutb)
{
	while (*coutb)
	{
		if (*coutb > 0)
		{
			rb(stackb);
			(*coutb)--;
		}
		else if (*coutb < 0)
		{
			rrb(stackb);
			(*coutb)++;
		}
	}
}

void	rev_rotaboth(t_tri **stacka, t_tri **stackb, t_tri *tmp)
{
	while (tmp->couta < 0 && tmp->coutb < 0)
	{
		tmp->couta++;
		tmp->coutb++;
		rrr(stacka, stackb);
	}
}

void	do_move(t_tri **stacka, t_tri **stackb, t_tri *tmp)
{
	if (tmp->couta < 0 && tmp->coutb < 0)
		rev_rotaboth(stacka, stackb, tmp);
	if (tmp->couta > 0 && tmp->coutb > 0)
		rotaboth(stacka, stackb, tmp);
	rotastacka(stacka, &tmp->couta);
	rotastackb(stackb, &tmp->coutb);
	pa(stacka, stackb);
}
