/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:33:38 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/20 14:21:23 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printp(unsigned long int l)
{
	char	*test;
	int		len;

	if (l == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	test = ft_itoa(l, 16);
	len = ft_putstr(test);
	free(test);
	return (len + 2);
}

int	ft_printd(int l)
{
	char	*d;
	int		len;

	d = ft_itoa2(l, 10);
	len = ft_putstr(d);
	free(d);
	return (len);
}

int	ft_printu(unsigned int l)
{
	char	*d;
	int		len;

	d = ft_itoa(l, 10);
	len = ft_putstr(d);
	free(d);
	return (len);
}

int	ft_printx(unsigned int l)
{
	char	*test;
	int		len;

	test = ft_itoa(l, 16);
	len = ft_putstr(test);
	free(test);
	return (len);
}

int	ft_printxc(unsigned int l)
{
	char	*test;
	int		len;

	test = ft_itoa_maj(l, 16);
	len = ft_putstr(test);
	free(test);
	return (len);
}
