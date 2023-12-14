/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:25:33 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/14 12:12:09 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

t_tri	*find_cheapest(t_tri **stackb)
{
	t_tri	*tmp;
	t_tri	*cheapests;
	int		cheapest;

	tmp = *stackb;
	cheapest = 2147483647;
	while (tmp)
	{
		if (nb_abs(tmp->couta) + nb_abs(tmp->coutb) < (cheapest))
		{
			cheapest = nb_abs(tmp->coutb) + nb_abs(tmp->couta);
			cheapests = tmp;
		}
		tmp = tmp->head;
	}
	return (cheapests);
}

void	sorting(t_tri **stacka, t_tri **stackb)
{
	t_tri	*cheapest;

	if (taille(*stacka) > 5)
	{
		push_low_half(stacka, stackb);
		push_big_half(stacka, stackb);
	}
	else
	{
		pb(stacka, stackb);
		pb(stacka, stackb);
	}
	tritrois(stacka);
	while (*stackb)
	{
		init_target_pos(stacka, stackb);
		init_cout(stacka, stackb);
		cheapest = find_cheapest(stackb);
		do_move(stacka, stackb, cheapest);
	}
	if (!check(*stacka))
		replacing(stacka);
}

void	writelst(t_tri *stack)
{
	while (stack->head != NULL)
	{
		printf("stack : %d\n", stack->content);
		stack = stack->head;
	}
	printf("stack : %d\n", stack->content);
}

int	main(int argc, char **argv)
{
	t_tri	*stacka;
	t_tri	*stackb;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (checkargv(argv, argc) != 1)
		return (0);
	stacka = fillstack(argv);
	stackb = NULL;
	indexer(stacka, taille(stacka));
	if (taille(stacka) == 2 && !check(stacka))
		sa(&stacka);
	else if (taille(stacka) == 3 && !check(stacka))
		tritrois(&stacka);
	else if (taille(stacka) > 3 && !check(stacka))
		sorting(&stacka, &stackb);
	free_stack(&stacka);
	free_stack(&stackb);
	return (0);
}
