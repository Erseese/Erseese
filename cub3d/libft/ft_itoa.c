/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:52 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/10 10:20:34 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenint(long int d)
{
	int	x;

	x = 0;
	if (d < 0)
	{
		d = d * -1;
		x++;
	}
	while (d > 9)
	{
		d = d / 10;
		x++;
	}
	x++;
	return (x);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	nb;
	char		*result;

	nb = n;
	len = lenint(nb);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result[len] = '\0';
	len--;
	while (nb > 9)
	{
		result[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	result[len] = nb % 10 + 48;
	return (result);
}
