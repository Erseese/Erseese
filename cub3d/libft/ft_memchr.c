/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:11:21 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/09 16:23:38 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (*res == (unsigned char)c)
			return ((void *)res);
		i++;
		res++;
	}
	return (0);
}
