/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:46:48 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/28 12:28:04 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	get_position(t_tri **stack)
{
	t_tri	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp->position = i;
		tmp = tmp->head;
		i++;
	}
}

void	indexer(t_tri *atack, int taille)
{
	t_tri	*ptr;
	t_tri	*changed;
	int		value;
	int		i;

	i = 0;
	while (++i <= taille)
	{
		ptr = atack;
		changed = NULL;
		value = 2147483647;
		while (ptr)
		{
			if (ptr->content == INT_MAX && ptr->index == -1)
				ptr->index = taille;
			if (ptr->content < value && ptr->index == -1)
				echange(&value, &changed, &ptr, atack);
			else
				ptr = ptr->head;
		}
		if (changed != NULL)
			changed->index = i;
	}
}

void	get_cout(t_tri **stacka, t_tri **stackb)
{
	t_tri	*tmpa;
	t_tri	*tmpb;
	int		sizea;
	int		sizeb;

	sizea = taille(*stacka);
	sizeb = taille(*stackb);
	tmpa = *stacka;
	tmpb = *stackb;
	while (tmpb)
	{
		tmpb->coutb = tmpb->position;
		if (tmpb->coutb > sizeb / 2)
			tmpb->coutb = (sizeb - tmpb->position) * -1;
		tmpb->couta = tmpb->target;
		if (tmpb->target > sizea / 2)
			tmpb->couta = (sizea - tmpb->target) * -1;
		tmpb = tmpb->head;
	}
}

int	get_target(t_tri **stacka, int stackb_index, int tindex, int tpos)
{
	t_tri	*tmp;

	tmp = *stacka;
	while (tmp)
	{
		if (tmp->index > stackb_index && tmp->index < tindex)
		{
			tindex = tmp->index;
			tpos = tmp->position;
		}
		tmp = tmp->head;
	}
	if (tindex != 2147483647)
		return (tpos);
	tmp = *stacka;
	while (tmp)
	{
		if (tmp->index < tindex)
		{
			tindex = tmp->index;
			tpos = tmp->position;
		}
		tmp = tmp->head;
	}
	return (tpos);
}

void	get_target_pos(t_tri **stacka, t_tri **stackb)
{
	t_tri	*tmp2;
	int		tpos;

	get_position(stacka);
	get_position(stackb);
	tmp2 = *stackb;
	tpos = 0;
	while (tmp2)
	{
		tpos = get_target(stacka, tmp2->index, 2147483647, tpos);
		tmp2->target = tpos;
		tmp2 = tmp2->head;
	}
}
