/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:05:43 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/19 13:38:00 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	find_path(int i, int j, char **map, char c)
{
	if (map[i][j] == c)
		return (1);
	if (map[i][j] == '0' || map[i][j] == 'P' || \
	map[i][j] == 'C')
	{
		map[i][j] = '1';
		if (find_path(i, j + 1, map, c))
			return (1);
		else if (find_path(i, j - 1, map, c))
			return (1);
		else if (find_path(i + 1, j, map, c))
			return (1);
		else if (find_path(i - 1, j, map, c))
			return (1);
	}
	return (0);
}

static int	find_path_collec(int i, int j, char **map)
{
	if (map[i][j] == '0' || map[i][j] == 'P' || \
	map[i][j] == 'C')
	{
		map[i][j] = '1';
		if (find_path_collec(i, j + 1, map))
			return (1);
		else if (find_path_collec(i, j - 1, map))
			return (1);
		else if (find_path_collec(i + 1, j, map))
			return (1);
		else if (find_path_collec(i - 1, j, map))
			return (1);
	}
	return (0);
}

int	check_sortie(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x][y] != 'P')
	{
		y = 0;
		while (map[x][y] != 'P' && map[x][y])
			y++;
		if (map[x][y] != 'P')
			x++;
	}
	if (find_path(x, y, map, c) == 1)
		return (1);
	return (0);
}

static void	check_path_collec(char **map, t_map *check)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\n' && map[x][y] != '\0')
		{
			if (map[x][y] == 'C')
				functionerror("collectible pas atteignable", check);
			y++;
		}
		x++;
	}
}

void	check_collectibles(char **map, t_map *check)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x][y] != 'P')
	{
		y = 0;
		while (map[x][y] != 'P' && map[x][y] && map[x][y] != '\n')
			y++;
		if (map[x][y] != 'P')
			x++;
	}
	find_path_collec(x, y, map);
	check_path_collec(map, check);
}
