/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:11:10 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/26 15:00:03 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void	errorfunction(char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\nError\n", 7);
	exit(1);
}

void	is_all_digit(char **argv)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (is_digit(argv[index]) == 0)
			errorfunction("It's not digit");
		index++;
	}
}

void	parsing(char **argv)
{
	int	i;

	is_all_digit(argv);
	i = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) >= 11)
			errorfunction("The result is > int max");
		if (ft_atoi2(argv[i]) > INT_MAX || ft_atoi2(argv[i]) < INT_MIN)
			errorfunction("The result is > int max");
		if (ft_atoi2(argv[i]) < 0)
			errorfunction("The result is < 0");
	}
	if (ft_atoi2(argv[1]) == 0)
		errorfunction("need more philosophers");
}
