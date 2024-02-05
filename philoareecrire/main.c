/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:05 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/05 23:47:19 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	free_everything(t_global *global)
{
	int	n;

	n = 0;
	while (n < global->numberphilos)
	{
		pthread_mutex_destroy(&global->allforks[n]);
		n++;
	}
	pthread_mutex_destroy(&global->eating);
	pthread_mutex_destroy(&global->writing);
	pthread_mutex_destroy(&global->dead);
	free(global->allforks);
	free(global->philo);
}

int	check_maxeat(t_global *check)
{
	int	b;

	b = 0;
	pthread_mutex_lock(&check->dead);
	while (check->philo[0].nop > b)
	{
		pthread_mutex_lock(&check->eating);
		if (check->philo[b].nbrofmeal < check->nbr_to_eat)
		{
			pthread_mutex_unlock(&check->eating);
			pthread_mutex_unlock(&check->dead);
			return (0);
		}
		pthread_mutex_unlock(&check->eating);
		b++;
	}	
	check->cond_death = 1;
	pthread_mutex_unlock(&check->dead);
	return (1);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead);
	pthread_mutex_lock(philo->eating);
	pthread_mutex_lock(philo->writing);
	if (get_current_time(philo->time) - philo->timelastmeal > philo->time_to_die)
	{
		pthread_mutex_unlock(philo->writing);
		pthread_mutex_unlock(philo->eating);
		pthread_mutex_lock(philo->writing);
		printf("%ld %d died\n", get_current_time(philo->time), philo->number);
		pthread_mutex_unlock(philo->writing);
		*philo->condd_death = 1;
		pthread_mutex_unlock(philo->dead);
		return (1);
	}
	pthread_mutex_unlock(philo->writing);
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->dead);
	return (0);
}

void	*checkdeath(void *arg)
{
	t_global	*control;
	int			index;
	int			death_bool;

	death_bool = 0;
	control = (t_global *)arg;
	while (control->cond_death == 0)
	{
		index = 0;
		while (index < control->philo[0].nop)
		{
			if (is_dead(&control->philo[index]) == 1)
			{
				death_bool = 1;
				break ;
			}
			index++;
		}
		if (control->argctest == 6)
		{
			if (check_maxeat(control) == 1 && death_bool != 1)
				break ;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	main_struct;

	if (argc != 5 && argc != 6)
		return (0);
	if (checkargv(argv, argc) == 0)
		return (0);
	initglobal(&main_struct, argv, argc);
	initpthread(&main_struct);
	/*for(int i = 0; ft_atoi(argv[1]) > i; i++)
	{
		printf("number %d ate : %d\n", main_struct.philo[i].number, main_struct.philo[i].nbrofmeal);
	}*/
	free_everything(&main_struct);
	return (0);
}
