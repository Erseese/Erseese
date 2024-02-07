/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:05 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 12:12:45 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_global *global)
{
	int	n;

	n = 0;
	while (n < global->numberphilos)
	{
		pthread_mutex_destroy(&global->allforks[n]);
		n++;
	}
	pthread_mutex_destroy(&global->eating);
	pthread_mutex_destroy(&global->writing);
	pthread_mutex_destroy(&global->dead);
	free(global->allforks);
	free(global->philo);
}

int	main(int argc, char **argv)
{
	t_global	main_struct;

	if (argc != 5 && argc != 6)
		return (0);
	if (checkargv(argv, argc) == 0)
		return (0);
	init_global(&main_struct, argv, argc);
	start_pthread(&main_struct);
	free_everything(&main_struct);
	return (0);
}
