/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:31 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 13:08:13 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	count(char *strr)
{
	int	i;

	i = 0;
	while (strr[i] != '\0' && strr[i] != '\n')
		i++;
	if (strr[i] == '\n')
		i++;
	return (i);
}

static char	*putstat(char *strr)
{
	char	*newstat;
	int		i;
	int		z;

	z = 0;
	if (!strr[0])
	{
		free(strr);
		return (NULL);
	}
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

static char	*readfile(int fd, char *stat)
{
	int		lis;
	char	*buffer;

	lis = 1;
	while (is_charset(stat) != 1 && lis != 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		lis = read(fd, buffer, BUFFER_SIZE);
		if (lis != -1)
			buffer[lis] = '\0';
		if (lis == -1)
		{
			free(buffer);
			return (NULL);
		}
		stat = ft_strjoin(stat, buffer);
		free(buffer);
	}
	return (stat);
}

static char	*putline(char *stat)
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
		return (NULL);
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
	static char	*stat[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat[fd] = readfile(fd, stat[fd]);
	if (stat[fd] == NULL)
		return (NULL);
	line = putline(stat[fd]);
	stat[fd] = putstat(stat[fd]);
	return (line);
}
/*int	main()
{
	int i = open("big.ber", O_RDONLY);
	char	*buf;
	//printf("%s", get_next_line(i));
	while ((buf = get_next_line(i)))
	{
		printf("%s", buf);
		free(buf);
	}
	//printf("%s%s",get_next_line(i),get_next_line(i));
	close(i);
	return (0);
}*/
