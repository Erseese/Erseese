/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:16:51 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/18 15:27:35 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	if (fd < 0)
		return ;
	l = n;
	if (l < 0)
	{
		l = l * -1;
		write(fd, "-", 1);
	}
	if (l > 9)
		ft_putnbr_fd((l / 10), fd);
	ft_putchar_fd((l % 10) + 48, fd);
}
