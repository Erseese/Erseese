/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:36:32 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/17 17:42:06 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*test;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (0);
	test = (void *)malloc(nmemb * size);
	if (test == NULL)
		return (NULL);
	ft_bzero(test, size * nmemb);
	return (test);
}
