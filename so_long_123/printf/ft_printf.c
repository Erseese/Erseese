/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:33:20 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/25 15:39:42 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	choix_fonct(va_list ptr, const char *d)
{
	int	len;

	len = 0;
	d++;
	if (*d == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (*d == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (*d == 'p')
		len += ft_printp(va_arg(ptr, unsigned long int));
	else if (*d == 'd')
		len += ft_printd(va_arg(ptr, int));
	else if (*d == 'i')
		len += ft_printd(va_arg(ptr, int));
	else if (*d == 'u')
		len += ft_printu(va_arg(ptr, unsigned int));
	else if (*d == 'x')
		len += ft_printx(va_arg(ptr, int));
	else if (*d == 'X')
		len += ft_printxc(va_arg(ptr, int));
	else if (*d == '%')
		len += ft_putchar('%');
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *d, ...)
{
	va_list	ptr;
	int		res;
	int		len;

	len = 0;
	res = 0;
	va_start(ptr, d);
	while (*d)
	{
		if (*d == '%')
		{
			len += choix_fonct(ptr, d);
			if (res == -1)
				return (0);
			d += 2;
		}
		else
		{
			write(1, d, 1);
			d++;
			len++;
		}
	}
	va_end(ptr);
	return (len);
}
