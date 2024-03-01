/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:14:34 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/10 10:15:20 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		index;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	index = 0;
	result = (char *)malloc((i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i > index)
	{
		result[index] = s[index];
		result[index] = (*f)(index, result[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
