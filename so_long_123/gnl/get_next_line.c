/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:31 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/25 15:39:09 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	count(char *strr)
{
	int	i;

	i = 0;
	while (strr[i] != '\0' && strr[i] != '\n')
		i++;
	if (strr[i] == '\n')
		i++;
	return (i);
}

char	*putstat(char *strr)
{
	char	*newstat;
	int		i;
	int		z;

	z = 0;
	if (!strr[0])
		return (free(strr), NULL);
	i = count(strr);
	newstat = malloc((ft_strlen(strr) - i + 1) * sizeof(char));
	if (newstat == NULL)
	{
		free(strr);
		return (NULL);
	}
	while (strr[i + z])
	{
		newstat[z] = strr[i + z];
		z++;
	}
	newstat[z] = '\0';
	free(strr);
	return (newstat);
}

char	*readfile(int fd, char *stat)
{
	int		lis;
	char	*buffer;

	lis = 1;
	while (is_charset(stat) != 1 && lis != 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (free(stat), NULL);
		lis = read(fd, buffer, BUFFER_SIZE);
		if (lis != -1)
			buffer[lis] = '\0';
		if (lis == -1)
		{
			free(buffer);
			return (free(stat), NULL);
		}
		stat = ft_strjoin(stat, buffer);
		free(buffer);
		if (stat == NULL)
			return (NULL);
	}
	return (stat);
}

char	*putline(char *stat)
{
	char	*line;
	int		i;
	int		z;

	z = 0;
	i = 0;
	if (stat[i] == 0)
		return (NULL);
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
	{
		free(stat);
		return (NULL);
	}
	line[i] = '\0';
	while (z < i)
	{
		line[z] = stat[z];
		z++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = readfile(fd, stat);
	if (stat == NULL)
		return (NULL);
	line = putline(stat);
	stat = putstat(stat);
	return (line);
}
