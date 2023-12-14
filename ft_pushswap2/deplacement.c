/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:44:11 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/16 13:42:41 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

int	check(t_tri *stack)
{
	while (stack->head != NULL)
	{
		if (stack->index > stack->head->index)
			return (0);
		stack = stack->head;
	}
	return (1);
}

t_tri	*go_end(t_tri *end)
{
	if (end == NULL)
		return (end);
	while (end->head != NULL)
		end = end->head;
	return (end);
}

t_tri	*go_end_minus_1(t_tri *end)
{
	if (end == NULL)
		return (end);
	while (end->head->head != NULL)
		end = end->head;
	return (end);
}
