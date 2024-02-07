/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:08:19 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 12:13:23 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		write(fd, &s[i++], 1);
	return (0);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	checkargv(char **argv, int argc)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (++i < argc)
	{
		if (ft_atoi2(argv[i]) > 2147483647 || ft_atoi2(argv[i]) < 0)
			return (ft_putstr_fd("Error\n", 2));
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			argv[i]++;
			w = 1;
		}
		if (!ft_isdigit(argv[i]))
			return (ft_putstr_fd("Error\n", 2));
		if (--w == 0)
			argv[i]--;
	}
	return (1);
}
