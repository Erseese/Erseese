/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:09:02 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 12:12:31 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

long	get_current_time(long times)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - times);
}

void	print_everything(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->dead);
	if (*(philo->condd_death) == 0)
	{
		pthread_mutex_unlock(philo->dead);
		if (ft_strcmp(action, "FORK") == 0)
		{
			pthread_mutex_lock(philo->writing);
			printf("%ld %d has taken a fork\n", \
			get_current_time(philo->time), philo->number);
			pthread_mutex_unlock(philo->writing);
		}
		else
		{
			pthread_mutex_lock(philo->writing);
			printf("%ld %d is %s\n", get_current_time(philo->time), \
			philo->number, action);
			pthread_mutex_unlock(philo->writing);
		}
	}
	else
		pthread_mutex_unlock(philo->dead);
}
