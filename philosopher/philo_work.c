/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:42:53 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/08 17:07:48 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*forking(t_philo *philo)
{
	if (philo->number % 2)
	{
		pthread_mutex_lock(philo->forkl);
		print_everything(philo, "FORK");
		if (philo->nop == 1)
		{
			pthread_mutex_unlock(philo->forkl);
			return (usleep(philo->time_to_die * 1000), NULL);
		}
		pthread_mutex_lock(philo->forkr);
		print_everything(philo, "FORK");
	}
	else
	{
		pthread_mutex_lock(philo->forkr);
		print_everything(philo, "FORK");
		if (philo->nop == 1)
		{
			pthread_mutex_unlock(philo->forkr);
			return (usleep(philo->time_to_die * 1000), NULL);
		}
		pthread_mutex_lock(philo->forkl);
		print_everything(philo, "FORK");
	}
	return (NULL);
}

static void	thinking(t_philo *philo)
{
	print_everything(philo, "thinking");
}

static void	sleeping(t_philo *philo)
{
	print_everything(philo, "sleeping");
	usleep(philo->time_to_sleep * 1000);
}

static void	eating(t_philo *philo)
{
	if (!forking(philo))
		return ;
	print_everything(philo, "eating");
	pthread_mutex_lock(philo->eating);
	philo->timelastmeal = get_current_time(philo->time);
	philo->nbrofmeal++;
	pthread_mutex_unlock(philo->eating);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->forkr);
	pthread_mutex_unlock(philo->forkl);
}

void	*work_philo(void *philoso)
{
	t_philo	*process;

	process = (t_philo *)philoso;
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
