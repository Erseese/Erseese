/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:32:25 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/22 18:30:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	taille;

	taille = 0;
	while (s[taille])
		taille++;
	while (taille != 0 && s[taille] != (char)c)
		taille--;
	if (s[taille] == (char)c)
		return ((char *)&s[taille]);
	return (NULL);
}
