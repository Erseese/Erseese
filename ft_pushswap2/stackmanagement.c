/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmanagement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:52:15 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/17 16:34:20 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	free_stack(t_tri **stack)
{
	t_tri	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->head;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_tri	*initstack(int content)
{
	t_tri	*test;

	test = (t_tri *)malloc(sizeof(t_tri));
	if (test == NULL)
		return (NULL);
	test->content = content;
	test->index = -1;
	test->target = -1;
	test->position = -1;
	test->couta = -1;
	test->coutb = -1;
	test->head = NULL;
	return (test);
}

int	taille(t_tri *start)
{
	int	count;

	count = 1;
	if (start == NULL)
		return (0);
	while (start->head != NULL)
	{
		start = start->head;
		count++;
	}
	return (count);
}

void	add_end(t_tri **test, t_tri *new)
{
	t_tri	*start;

	if (*test == NULL)
		*test = new;
	else
	{
		start = go_end(*test);
		start->head = new;
	}
}

t_tri	*fillstack(char **argv)
{
	int		i;
	t_tri	*lst;
	t_tri	*new;

	i = 1;
	lst = NULL;
	new = NULL;
	while (argv[i])
	{
		if (i == 1)
			lst = initstack(ft_atoi(argv[i]));
		else
		{
			new = initstack(ft_atoi(argv[i]));
			add_end(&lst, new);
		}
		i++;
	}
	return (lst);
}
