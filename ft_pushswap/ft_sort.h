/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:24:59 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 18:20:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_tri
{
	int				content;
	int				index;
	int				position;
	int				target;
	int				couta;
	int				coutb;
	struct s_tri	*head;
}			t_tri;

/* part 1 initialisation :D*/
int	ft_putstr_fd(char *s, int fd);
void	add_end(t_tri **test, t_tri *new);//done
t_tri	*initstack(int content);//done
int		taille(t_tri *start);//done
int		ft_atoi(const char *nptr);
t_tri	*fillstack(char **argv);//done
void	indexer(t_tri *atack, int taille);
t_tri	*go_end_minus_1(t_tri *end);
t_tri	*go_end(t_tri *end);

/* all command (part2)*/
int	checkargv(char **argv, int argc);
void	swap(t_tri *stack);
void	sa(t_tri **a);
void	sb(t_tri **b);
void	ss(t_tri **a, t_tri **b);

void	rotate(t_tri **stack);
void	ra(t_tri **a);
void	rb(t_tri **b);
void	rr(t_tri **a, t_tri **b);

void	rrotate(t_tri **stack);
void	rra(t_tri **a);
void	rrb(t_tri **b);
void	rrr(t_tri **a, t_tri **b);

void	push(t_tri **stacka, t_tri **stackb);
void	pb(t_tri **pa, t_tri **pb);
void	pa(t_tri **pa, t_tri **pb);

/*part 3 */
int		check(t_tri *stack);
void	tritrois(t_tri **stack);
void	writelst(t_tri *stack);
void	get_position(t_tri **stack);
//void	get_target(t_tri **stacka, t_tri **stackb);
void	get_target_pos(t_tri **stacka, t_tri **stackb);
int		writelstpostarg(t_tri *stack);
void	dsasort(t_tri **stacka, t_tri **stackb);
void	shift_tri(t_tri **stack_a);
void	push_all_save_three(t_tri **stack_a, t_tri **stack_b);
void	get_cheapest(t_tri **stacka, t_tri **stackb);
void	do_move(t_tri **stacka, t_tri **stackb, int couta, int coutb);
void	rev_rotaboth(t_tri **stacka, t_tri **stackb, int *couta, int *coutb);
void	rotastackb(t_tri **stackb, int *coutb);
void	rotastacka(t_tri **stacka, int *couta);
void	rotaboth(t_tri **stacka, t_tri **stackb, int *couta, int *coutb);
void	get_cout(t_tri **stacka, t_tri **stackb);
int		is_sorted(t_tri *stack);
int		get_lowest_index_position(t_tri **stack);
int		nb_abs(int nb);
void	free_stack(t_tri **stack);
int		get_target(t_tri **stacka, int stackb_index, int tindex, int tpos);
void	echange(int *v, t_tri **changed, t_tri **ptr, t_tri *atack);

#endif