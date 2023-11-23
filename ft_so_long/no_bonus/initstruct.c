/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:10:34 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/21 15:10:51 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**get_map(int fd, t_map *mapper)
{
	char	*map_line;
	char	*line;
	char	**map;

	map_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	if (!map)
		functionerror("Problem collect the map", mapper);
	return (map);
}

void	initmap(t_map *map, char *file)
{
	map->player = 0;
	map->exit = 0;
	map->collectibles = 0;
	map->mur = 0;
	map->vide = 0;
	map->l = 0;
	map->map = get_map(open(file, O_RDONLY), map);
	map->mapbis = get_map(open(file, O_RDONLY), map);
	map->maptemp = get_map(open(file, O_RDONLY), map);
	map->taillemap = (int)ft_strlen(map->map[0]);
}
