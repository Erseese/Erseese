/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:33:51 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 12:11:24 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (get_current_time(philo->time) - \
	philo->timelastmeal > philo->time_to_die)
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

void	*check_death(void *arg)
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
