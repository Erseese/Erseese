/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:26:25 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/01 19:06:57 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_struct(t_file *init)
{
	t_file	*tmp;

	while (init->next)
	{
		tmp = init->next;
		free(init->line);
		free(init);
		init = tmp;
	}
	free(init->line);
	free(init);
}

t_file	*lstlast(t_file *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_file	*lstnew(char *line)
{
	t_file	*stru;

	stru = (t_file *)malloc(sizeof(t_file));
	if (stru == NULL)
		return (NULL);
	stru->line = line;
	stru->next = NULL;
	return (stru);
}

void	lstadd_back(t_file **lst, t_file *new)
{
	t_file	*pointer;
	t_file	*start;

	if (lst == NULL || new == NULL)
		return ;
	pointer = *lst;
	start = *lst;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		pointer = lstlast(*lst);
		pointer->next = new;
	}
}

void	get_cubfile(t_file **init, char *file)
{
	int		fd;
	t_file	*new;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		new = lstnew(line);
		lstadd_back(init, new);
		line = get_next_line(fd);
	}
	if (errno != 0)
	{
		free_struct(*init);
		ft_putstr_fd("Error\n get next line flopped", 1);
		exit(EXIT_FAILURE);
	}
}
