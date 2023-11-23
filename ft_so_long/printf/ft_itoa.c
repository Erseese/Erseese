/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:30:38 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/22 17:59:56 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_taille(unsigned long int nb, unsigned long int base)
{
	long int	li;

	li = 0;
	if (nb < 0)
	{
		nb = -nb;
		li++;
	}
	while (nb > base - 1)
	{
		li++;
		nb = nb / base;
	}
	li++;
	return (li);
}

char	*ft_itoa(unsigned long int nb, unsigned long int base)
{
	int		taille;
	char	*res;

	taille = ft_taille(nb, base);
	res = malloc((1 + taille) * sizeof(char));
	if (res == NULL)
		return (0);
	res[taille] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	taille--;
	while (base - 1 < nb)
	{
		res[taille] = "0123456789abcdef"[nb % base];
		nb = nb / base;
		taille--;
	}
	res[taille] = "0123456789abcdef"[nb % base];
	nb = nb / base;
	return (res);
}

char	*ft_itoa_maj(unsigned long int nb, unsigned long int base)
{
	long int	taille;
	char		*res;

	taille = ft_taille(nb, base);
	res = malloc((1 + taille) * sizeof(char));
	if (res == NULL)
		return (0);
	res[taille] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	taille--;
	while (base - 1 < nb)
	{
		res[taille] = "0123456789ABCDEF"[nb % base];
		nb = nb / base;
		taille--;
	}
	res[taille] = "0123456789ABCDEF"[nb % base];
	nb = nb / base;
	return (res);
}

int	ft_taille2(long int nb, long int base)
{
	long int	li;

	li = 0;
	if (nb < 0)
	{
		nb = -nb;
		li++;
	}
	while (nb > base - 1)
	{
		li++;
		nb = nb / base;
	}
	li++;
	return (li);
}

char	*ft_itoa2(long int nb, long int base)
{
	int		taille;
	char	*res;

	taille = ft_taille2(nb, base);
	res = malloc((1 + taille) * sizeof(char));
	if (res == NULL)
		return (0);
	res[taille] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	taille--;
	while (base - 1 < nb)
	{
		res[taille] = "0123456789abcdef"[nb % base];
		nb = nb / base;
		taille--;
	}
	res[taille] = "0123456789abcdef"[nb % base];
	nb = nb / base;
	return (res);
}
