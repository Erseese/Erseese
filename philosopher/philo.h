/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:43:11 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/06 12:29:12 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	pthread_t		process;
	int				nop; //number_of_times_each_philosopher_must_eat
	int				time_to_eat;
	int				*condd_death;
	int				time_to_sleep;
	int				number;
	int				time_to_die;
	int				timelastmeal;
	int				nbrofmeal;
	long			time;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*dead;
}				t_philo;

typedef struct s_global
{
	int				numberphilos;
	int				cond_death;
	int				nbr_to_eat;
	int				argctest;
	long			time;
	pthread_mutex_t	*allforks;
	t_philo			*philo;
	pthread_mutex_t	eating;
	pthread_mutex_t	writing;
	pthread_mutex_t	dead;
	pthread_mutex_t	finishedeat;
}				t_global;

int				checkargv(char **argv, int argc);
int				ft_atoi(const char *nptr);
void			init_global(t_global *idk, char **argv, int argc);
int				ft_putstr_fd(char *s, int fd);
long long int	ft_atoi2(const char *nptr);
long			get_current_time(long time);
int				ft_putstr_fd(char *s, int fd);
void			start_pthread(t_global *idk);
void			*work_philo(void *idk);
void			print_everything(t_philo *philo, char *action);
void			*check_death(void *yey);
void			parsing(char **argv);

#endif