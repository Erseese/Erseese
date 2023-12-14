/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commonfunction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:57:33 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/01 11:50:15 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

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

long long int	ft_atoi2(const char *nptr)
{
	int				i;
	int				negatif;
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

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	echange(int *v, t_tri **changed, t_tri **ptr, t_tri *atack)
{
	*v = (*ptr)->content;
	*changed = *ptr;
	*ptr = atack;
}
