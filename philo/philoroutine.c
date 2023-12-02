/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoroutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:42:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/30 17:05:16 by ytouihar         ###   ########.fr       */
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
	ft_usleep(philo->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->forkl);
	printeverything(philo, "FORK");
	if (philo->notepme == 1)
	{
		pthread_mutex_unlock(philo->forkl);
		ft_usleep(philo->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->forkr);
	printeverything(philo, "FORK");
	printeverything(philo, "eating");
	pthread_mutex_lock(philo->eating);
	philo->timelastmeal = get_current_time();
	philo->nbrofmeal++;
	pthread_mutex_unlock(philo->eating);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(philo->forkr);
}

void	*routinephilo(void *idk)
{
	t_philo	*t;

	t = (t_philo *)idk;
	if (t->number % 2 == 0)
		ft_usleep(t->time_to_eat / 10);
	while (*t->condd_death == 0)
	{
		thinking(t);
		sleeping(t);
		eating(t);
	}
	return (0);
}
