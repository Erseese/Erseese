/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:42:53 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 12:12:01 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_mutex_lock(philo->forkl);
	print_everything(philo, "FORK");
	if (philo->nop == 1)
	{
		pthread_mutex_unlock(philo->forkl);
		usleep(philo->time_to_die * 1000);
		return ;
	}
	pthread_mutex_lock(philo->forkr);
	print_everything(philo, "FORK");
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
	if (process->number % 2 == 1)
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
