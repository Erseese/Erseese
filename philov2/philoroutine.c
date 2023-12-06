/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoroutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:42:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/06 17:24:50 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	thinking(t_philo *philo)
{
	printeverything(philo, "thinking");
}

void	sleeping(t_philo *philo)
{
	printeverything(philo, "sleeping");
	usleep(philo->time_to_sleep * 1000);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->forkl);
	printeverything(philo, "FORK");
	if (philo->notepme == 1)
	{
		pthread_mutex_unlock(philo->forkl);
		usleep(philo->time_to_die * 1000);
		return ;
	}
	pthread_mutex_lock(philo->forkr);
	printeverything(philo, "FORK");
	printeverything(philo, "eating");
	pthread_mutex_lock(philo->dead);
	philo->timelastmeal = get_current_time(philo->time);
	philo->nbrofmeal++;
	pthread_mutex_unlock(philo->dead);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(philo->forkr);
}

void	*routinephilo(void *idk)
{
	t_philo	*t;

	t = (t_philo *)idk;
	if (t->number % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(t->dead);
	while (*t->condd_death == 0)
	{
		pthread_mutex_unlock(t->dead);
		thinking(t);
		sleeping(t);
		eating(t);
		pthread_mutex_lock(t->dead);
	}
	pthread_mutex_unlock(t->dead);
	return (0);
}
