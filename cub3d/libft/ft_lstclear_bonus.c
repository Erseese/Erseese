/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:46:19 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/18 15:00:09 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*move;
	t_list	*temp;

	move = *lst;
	if (lst == NULL || del == NULL)
		return ;
	while (move)
	{
		temp = move->next;
		ft_lstdelone(move, del);
		move = temp;
	}
	*lst = NULL;
}
