/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:25:33 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 18:27:37 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	get_cheapest(t_tri **stacka, t_tri **stackb)
{
	t_tri	*tmp;
	int		cheapest;
	int		cheapestcouta;
	int		cheapestcoutb;

	tmp = *stackb;
	cheapest = 2147483647;
	while (tmp)
	{
		if (nb_abs(tmp->couta) + nb_abs(tmp->coutb) < (cheapest))
		{
			cheapest = nb_abs(tmp->coutb) + nb_abs(tmp->couta);
			cheapestcouta = tmp->couta;
			cheapestcoutb = tmp->coutb;
		}
		tmp = tmp->head;
	}
	do_move(stacka, stackb, cheapestcouta, cheapestcoutb);
}

void	sorting(t_tri **stacka, t_tri **stackb)
{
	push_all_save_three(stacka, stackb);
	tritrois(stacka);
	while (*stackb)
	{
		get_target_pos(stacka, stackb);
		get_cout(stacka, stackb);
		get_cheapest(stacka, stackb);
	}
	if (!check(*stacka))
		shift_tri(stacka);
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
		write(2, "ERROR\n", 5);
		return (0);
	}
	if (checkargv(argv) == 0)
		return (0);
	stacka = fillstack(argv);
	stackb = NULL;
	indexer(stacka, taille(stacka));
	if (taille(stacka) == 1)
		return (0);
	else if (taille(stacka) == 2 && !check(stacka))
		sa(&stacka);
	else if (taille(stacka) == 3 && !check(stacka))
		tritrois(&stacka);
	else if (!check(stacka))
		sorting(&stacka, &stackb);
	free_stack(&stacka);
	free_stack(&stackb);
	return (0);
}
