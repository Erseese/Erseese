/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:09:00 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/28 17:56:48 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

long long int	ft_atoi2(const char *nptr)
{
	int	i;
	int	negatif;
	long long int	res;

	i = 0;
	res = 0;
	negatif = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negatif = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * negatif);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negatif;
	int	res;

	i = 0;
	res = 0;
	negatif = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negatif = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * negatif);
}