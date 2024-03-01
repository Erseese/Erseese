/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:18:51 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/18 15:29:52 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(find) == 0)
		return ((char *)s);
	while (s[i] && i < slen)
	{
		if (ft_strncmp((char *)&s[i], find, ft_strlen(find)) == 0)
		{
			if (i + ft_strlen(find) > slen)
				return (0);
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
