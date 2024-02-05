/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoroutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:42:53 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/06 00:01:08 by ersees           ###   ########.fr       */
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
	if (philo->nop == 1)
	{
		pthread_mutex_unlock(philo->forkl);
		usleep(philo->time_to_die * 1000);
		return ;
	}
	pthread_mutex_lock(philo->forkr);
	printeverything(philo, "FORK");
	printeverything(philo, "eating");
	pthread_mutex_lock(philo->eating);
	philo->timelastmeal = get_current_time(philo->time);
	philo->nbrofmeal++;
	pthread_mutex_unlock(philo->eating);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->forkr);
	pthread_mutex_unlock(philo->forkl);
}

void	*routinephilo(void *philoso)
{
	t_philo	*process;

	
	process = (t_philo *)philoso;
	if (process->number % 2 == 0)
		usleep(process->time_to_eat);
	pthread_mutex_lock(process->dead);
	while (*(process->condd_death) == 0)
	{
		pthread_mutex_unlock(process->dead);
		eating(process);
		sleeping(process);
		thinking(process);
		pthread_mutex_lock(process->dead);
	}
	pthread_mutex_unlock(process->dead);
	return (0);
}
