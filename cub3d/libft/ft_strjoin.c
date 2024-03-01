/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:07:30 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/10 10:20:27 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *dst, const char *src)
{
	char	*join;
	size_t	i;

	if (!src || !dst)
		return (NULL);
	i = 0;
	join = malloc((ft_strlen(dst) + ft_strlen(src) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (dst[i])
	{
		join[i] = dst[i];
		i++;
	}
	while (src[i - ft_strlen(dst)])
	{
		join[i] = src[i - ft_strlen(dst)];
		i++;
	}
	join[i] = '\0';
	return (join);
}
