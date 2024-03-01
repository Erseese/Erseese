/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:06:10 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/10 10:17:34 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	*str2;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (str > str2)
	{
		n = n - 1;
		while (i < n + 1)
		{
			str[n] = str2[n];
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		str[i] = str2[i];
			i++;
	}
	return (dest);
}
