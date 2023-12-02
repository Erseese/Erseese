/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:43 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/01 09:30:20 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_charset(char *i)
{
	size_t	test;

	test = 0;
	if (!i)
		return (0);
	while (i[test])
	{
		if (i[test] == '\n')
			return (1);
		test++;
	}
	return (0);
}

static char	*test(char	*dst)
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
		dst = test(dst);
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
	free(dst);
	return (join);
}
