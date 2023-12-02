/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:31:49 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/01 10:50:18 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

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

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

int	checkargv(char **argv, int argc)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (++i < argc)
	{
		j = i;
		if (ft_atoi2(argv[i]) > INT_MAX || ft_atoi2(argv[i]) < INT_MIN)
			return (ft_putstr_fd("Error\n", 2));
		while (++j < argc - 1)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
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
