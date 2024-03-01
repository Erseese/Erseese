/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:38:55 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/09 11:48:50 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udest;
	unsigned char	*usrc;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	while (i < n)
	{
		udest[i] = usrc[i];
		i++;
	}
	return (dest);
}
