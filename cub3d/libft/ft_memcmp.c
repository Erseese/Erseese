/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:14:54 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/20 09:01:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*fs1;
	unsigned char	*fs2;
	size_t			i;

	i = 0;
	fs1 = (unsigned char *)s1;
	fs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && fs1[i] == fs2[i])
		i++;
	if (i < n)
	{
		if (fs1[i] != fs2[i])
			return (fs1[i] - fs2[i]);
	}
	return (0);
}
