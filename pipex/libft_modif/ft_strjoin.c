/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:44:46 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/24 14:55:33 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*vide(char	*dst)
{
	dst = (char *)malloc(1 * sizeof(char));
	dst[0] = '\0';
	return (dst);
}

char	*ft_strjoin(char *dst, char *src)
{
	char		*join;
	size_t		i;

	if (!dst)
		dst = vide(dst);
	if (!src)
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
	//free(dst);
	return (join);
}
