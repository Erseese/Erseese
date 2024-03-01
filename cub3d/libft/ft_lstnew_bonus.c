/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:47:06 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/17 18:00:43 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*stru;

	stru = (t_list *)malloc(sizeof(t_list));
	if (stru == NULL)
		return (NULL);
	stru->content = content;
	stru->next = NULL;
	return (stru);
}
