/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:45:02 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/05 23:53:53 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
/*boucle mutex fork*/
void	initphilos(t_global *infos, char **argv, int n)
{
	infos->philo[n].nop = ft_atoi(argv[1]); //number_of_philosopher
	infos->philo[n].time_to_die = ft_atoi(argv[2]);
	infos->philo[n].time_to_eat = ft_atoi(argv[3]);
	infos->philo[n].time_to_sleep = ft_atoi(argv[4]);
	infos->philo[n].number = n + 1;
	infos->philo[n].time = infos->time;
	infos->philo[n].timelastmeal = get_current_time(infos->time);
	infos->philo[n].nbrofmeal = 0;
	infos->philo[n].condd_death = &infos->cond_death;
	infos->philo[n].eating = &infos->eating;
	infos->philo[n].writing = &infos->writing;
	infos->philo[n].dead = &infos->dead;
	infos->philo[n].forkl = &infos->allforks[n];
	printf("fourchette gauche du philo %d : %p\n", n, &infos->allforks[n]);
	//printf()
	if (n == 0)
	{
		infos->philo[n].forkr = &infos->allforks[ft_atoi(argv[1]) - 1];
		printf("fourchette droite du philo %d : %p\n", n, &infos->allforks[ft_atoi(argv[1]) - 1]);
	}
	else
	{
		infos->philo[n].forkr = &infos->allforks[n - 1];
		printf("fourchette droite du philo %d : %p\n", n, &infos->allforks[n - 1]);
	}
}

void	initforks(t_global *threading, int max)
{
	int	n;

	n = 0;
	while (n < max)
	{
		pthread_mutex_init(&(threading->allforks[n]), NULL);
		n++;
	}
}

/*init global*/
void	initglobal(t_global *infos, char **argv, int argc)
{
	int	n;

	n = 0;
	infos->numberphilos = ft_atoi(argv[1]);
	infos->argctest = argc;
	if (argc == 6)
		infos->nbr_to_eat = ft_atoi(argv[5]);
	infos->cond_death = 0;
	infos->time = 0;
	infos->time = get_current_time(infos->time);
	infos->philo = malloc((infos->numberphilos) * sizeof(t_philo));
	if (infos->philo == NULL)
		return ;
	infos->allforks = malloc((infos->numberphilos) * sizeof(pthread_mutex_t));
	if (infos->allforks == NULL)
		return ;
	pthread_mutex_init(&(infos->writing), NULL);
	pthread_mutex_init(&(infos->dead), NULL);
	pthread_mutex_init(&(infos->eating), NULL);
	initforks(infos, ft_atoi(argv[1]));
	n = 0;
	while (n < ft_atoi(argv[1]))
	{
		initphilos(infos, argv, n);
		n++;
	}
}
/*create philo struct*/

/*boucle pthread philo*/
void	initpthread(t_global *global)
{
	pthread_t	checkall;
	int			index;

	index = 0;
	if (pthread_create(&checkall, \
		NULL, &checkdeath, global) != 0)
	{
		return ;
	}
	while (index < global->philo->nop)
	{
		if (pthread_create(&global->philo[index].process, \
			NULL, &routinephilo, &global->philo[index]) != 0)
		{
			return ;
		}
		index++;
	}
	index = 0;
	if (pthread_join(checkall, NULL) != 0)
		return ;
	while (index < global->philo[0].nop /*&& t->cond_death == 0*/)
	{
		if (pthread_join(global->philo[index].process, NULL) != 0)
			return ;
		index++;
	}
}
