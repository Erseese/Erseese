/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:53:14 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/29 11:53:16 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*curr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr = ft_readfile(fd, rest);
	line = ft_line(curr);
	rest = ft_aftline(curr);
	return (line);
}

char	*ft_aftline(char *curr)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (curr == NULL || curr[0] == 0)
	{
		free(curr);
		return (NULL);
	}
	while (curr[i] != '\n' && curr[i])
		i++;
	if (curr[i] == '\n')
		i++;
	new = malloc((ft_strlen(curr) + i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i--;
	while (curr[++i])
		new[j++] = curr[i];
	new[j] = '\0';
	free(curr);
	return (new);
}

char	*ft_line(char *curr)
{
	char	*new;
	int		i;

	i = 0;
	if (curr == NULL || curr[0] == 0)
		return (NULL);
	while (curr[i] != '\n' && curr[i])
		i++;
	if (curr[i] == '\n')
		i++;
	new = malloc((i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[i] = '\0';
	i = -1;
	while (curr[++i] != '\n' && curr[i])
		new[i] = curr[i];
	if (curr[i] == '\n')
		new[i] = curr[i];
	return (new);
}

int	ft_srch(char *src, char c)
{
	int	i;

	i = -1;
	if (!src)
		return (0);
	while (src[++i])
		if (src[i] == c)
			return (1);
	return (0);
}

char	*ft_readfile(int fd, char *rest)
{
	char	*buf;
	ssize_t	bitr;

	bitr = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (bitr != 0 && !ft_srch(rest, '\n'))
	{
		bitr = read(fd, buf, BUFFER_SIZE);
		if (bitr < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bitr] = '\0';
		rest = ft_join(rest, buf);
		if (!rest)
			return (NULL);
	}
	free(buf);
	return (rest);
}
