/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:43 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/19 16:11:11 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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

char	*test(char	*dst)
{
	if (!dst)
	{
		dst = (char *)malloc(1 * sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	return (dst);
}

char	*ft_strjoin(char *dst, char *src)
{
	char		*join;
	size_t		i;

	dst = test(dst);
	if (dst == NULL)
		return (NULL);
	if (!src)
		return (NULL);
	i = 0;
	join = malloc((ft_strlen(dst) + ft_strlen(src) + 1) * sizeof(char));
	if (join == NULL)
		return (free(dst), NULL);
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
