/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:45:02 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/07 10:37:06 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
/*boucle mutex fork*/
void	initphilos(t_global *idk, char **argv, int n)
{
	idk->philo[n].notepme = ft_atoi(argv[1]); //number_of_times_each_philosopher_must_eat
	idk->philo[n].time_to_die = ft_atoi(argv[2]);
	idk->philo[n].time_to_eat = ft_atoi(argv[3]);
	idk->philo[n].time_to_sleep = ft_atoi(argv[4]);
	idk->philo[n].number = n + 1;
	idk->philo[n].time = idk->time;
	idk->philo[n].timelastmeal = get_current_time(idk->time);
	idk->philo[n].nbrofmeal = 0;
	idk->philo[n].condd_death = &idk->cond_death;
	idk->philo[n].eating = &idk->eating;
	idk->philo[n].writing = &idk->writing;
	idk->philo[n].dead = &idk->dead;
	idk->philo[n].finishedeat = &idk->finishedeat;
	idk->philo[n].forkl = &idk->allforks[n];
	if (n == 0)
		idk->philo[n].forkr = &idk->allforks[ft_atoi(argv[1]) - 1];
	else
		idk->philo[n].forkr = &idk->allforks[n - 1];
}

void	initforks(t_global *idk, int max)
{
	int	n;

	n = 0;
	while (n < max)
	{
		pthread_mutex_init(&(idk->allforks[n]), NULL);
		n++;
	}
}

/*init global*/
void	initglobal(t_global *idk, char **argv, int argc)
{
	int	n;

	n = 0;
	idk->numberphilos = ft_atoi(argv[1]);
	idk->argctest = argc;
	if (argc == 6)
		idk->nbr_to_eat = ft_atoi(argv[5]);
	idk->cond_death = 0;
	idk->time = 0;
	idk->time = get_current_time(idk->time);
	idk->philo = malloc((idk->numberphilos) * sizeof(t_philo));
	if (idk->philo == NULL)
		return ;
	idk->allforks = malloc((idk->numberphilos) * sizeof(pthread_mutex_t));
	if (idk->allforks == NULL)
		return ;
	pthread_mutex_init(&(idk->writing), NULL);
	pthread_mutex_init(&(idk->dead), NULL);
	pthread_mutex_init(&(idk->eating), NULL);
	pthread_mutex_init(&(idk->finishedeat), NULL);
	initforks(idk, ft_atoi(argv[1]));
	n = 0;
	while (n < ft_atoi(argv[1]))
	{
		initphilos(idk, argv, n);
		n++;
	}
}
/*create philo struct*/

/*boucle pthread philo*/
void	initpthread(t_global *idk)
{
	t_global	*t;
	pthread_t	checkall;
	int			n;

	t = idk;
	n = 0;
	if (pthread_create(&checkall, \
		NULL, &checkdeath, t) != 0)
	{
		return ;
	}
	while (n < t->philo->notepme)
	{
		if (pthread_create(&t->philo[n].lalala, \
			NULL, &routinephilo, &t->philo[n]) != 0)
		{
			return ;
		}
		n++;
	}
	n = 0;
	if (pthread_join(checkall, NULL) != 0)
		return ;
	while (n < t->philo[0].notepme /*&& t->cond_death == 0*/)
	{
		if (pthread_join(t->philo[n].lalala, NULL) != 0)
			return ;
		n++;
	}
}
