/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:08:45 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/10 12:48:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftcharset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*uwu;
	int		i;
	int		w;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ftcharset(s1[i], set) == 1)
		i++;
	w = ft_strlen(s1) - 1;
	while (w >= 0 && ftcharset(s1[w], set) == 1)
		w--;
	w = w - i + 1;
	if (w < 0)
		w = 0;
	uwu = ft_substr(s1, i, w);
	return (uwu);
}
