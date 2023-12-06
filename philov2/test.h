/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:43:11 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/06 16:38:58 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		lalala;
	int				notepme; //number_of_times_each_philosopher_must_eat
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
}				t_global;

int				checkargv(char **argv, int argc);
int				ft_atoi(const char *nptr);
void			initglobal(t_global *idk, char **argv, int argc);
int				ft_putstr_fd(char *s, int fd);
long long int	ft_atoi2(const char *nptr);
long			get_current_time(long time);
int				ft_putstr_fd(char *s, int fd);
void			initpthread(t_global *idk);
void			*routinephilo(void *idk);
//int				ft_usleep(size_t milliseconds);
void			printeverything(t_philo *philo, char *action);
void			*checkdeath(void *yey);


#endif