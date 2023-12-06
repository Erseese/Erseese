/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:05 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/06 16:44:25 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	free_everything(t_global *yey)
{
	int	n;

	n = 0;
	while (n < yey->numberphilos)
	{
		pthread_mutex_destroy(&yey->allforks[n]);
		n++;
	}
	pthread_mutex_destroy(&yey->eating);
	pthread_mutex_destroy(&yey->writing);
	pthread_mutex_destroy(&yey->dead);
	free(yey->allforks);
	free(yey->philo);
}

int	check_maxeat(t_global *yey)
{
	int	b;

	b = 0;
	pthread_mutex_lock(&yey->dead);
	while (yey->philo[0].notepme > b)
	{
		if (yey->philo[b].nbrofmeal < yey->nbr_to_eat)
		{
			pthread_mutex_unlock(&yey->dead);
			return (0);
		}
		b++;
	}	
	yey->cond_death = 1;
	pthread_mutex_unlock(&yey->dead);
	return (1);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead);
	pthread_mutex_lock(philo->eating);
	if (get_current_time(philo->time) - philo->timelastmeal > philo->time_to_die)
	{
		printeverything(philo, "DIED");
		*philo->condd_death = 1;
		pthread_mutex_unlock(philo->eating);
		pthread_mutex_unlock(philo->dead);
		return (1);
	}
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->dead);
	return (0);
}

void	*checkdeath(void *yey)
{
	t_global	*youhou;
	int			n;
	int			youpi;

	youpi = 0;
	youhou = (t_global *)yey;
	while (youhou->cond_death == 0)
	{
		n = 0;
		while (n < youhou->philo[0].notepme)
		{
			if (is_dead(&youhou->philo[n]) == 1)
			{
				youpi = 1;
				break ;
			}
			n++;
		}
		if (youhou->argctest == 6)
		{
			if (check_maxeat(youhou) == 1 && youpi != 1)
				break ;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	yey;

	if (argc != 5 && argc != 6)
		return (0);
	if (checkargv(argv, argc) == 0)
		return (0);
	initglobal(&yey, argv, argc);
	initpthread(&yey);
	free_everything(&yey);
	return (0);
}
