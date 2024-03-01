/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:27:34 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/01 18:29:08 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	**map_copy(char **map)
{
	char	**copy_map;
	int		i;
	int		compteur;

	i = 0;
	compteur = find_longest_line(map, &i);
	copy_map = copy_right_with_spaces(map, i, compteur);
	return (copy_map);
}

static int	check_around(int i, int j, char **map, int type)
{
	if (map[i][j] == '\0' || map[i][j] == '0' || map[i][j] == 'N' \
	|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
		return (1);
	if (type == UP || type == DOWN)
	{
		if (map[i][j + 1] != '\0' && map[i][j + 1] == '0')
			return (1);
		if (map[i][j - 1] != '\0' && map[i][j - 1] == '0')
			return (1);
	}
	else
	{
		if (map[i - 1][j] != '\0' && map[i - 1][j] == '0')
			return (1);
		if (map[i + 1][j] != '\0' && map[i + 1][j] == '0')
			return (1);
	}
	return (0);
}

static int	find_path(int i, int j, char **map, int type)
{
	int	len_max;

	len_max = ft_strlen_matrice(map);
	if (check_around(i, j, map, type))
		return (1);
	if (map[i][j] == ' ')
	{
		map[i][j] = '2';
		if (type == UP)
			if ((i + 1 > len_max) && find_path(i + 1, j, map, type))
				return (1);
		if (type == DOWN)
			if ((i - 1 < 0) && find_path(i - 1, j, map, type))
				return (1);
		if (type == LEFT)
			if (find_path(i, j + 1, map, type))
				return (1);
		if (type == RIGHT)
			if (find_path(i, j - 1, map, type))
				return (1);
	}
	return (0);
}

int	check_correct_walls(char **map, int x, int y, int type)
{
	if (type == UP && find_path(x, y, map, type) == 1)
	{
		printf("mapfausseflope haut\n");
		return (1);
	}
	else if (type == DOWN && find_path(x, y, map, type) == 1)
	{
		printf("mapfausseflope bas\n");
		return (1);
	}
	else if (type == RIGHT && find_path(x, y, map, type) == 1)
	{
		printf("mapfausseflope droit\n");
		return (1);
	}
	else if (type == LEFT && find_path(x, y, map, type) == 1)
	{
		printf("mapfausseflope gauche\n");
		return (1);
	}
	return (0);
}

int	parsing_map(t_parse *parsed)
{
	int		i;
	int		j;
	char	**copy_map;

	j = 0;
	i = 0;
	copy_map = map_copy(parsed->map);
	if (check_inside(parsed) == 1 || parsed->player_position == 0)
	{
		printf("mapfausseflope player%d\n", parsed->player_position);
		return (free_map(copy_map), 1);
	}
	if (handle_right(copy_map) == 1)
		return (free_map(copy_map), 1);
	while (copy_map[++j + 1] != NULL)
		if (check_correct_walls(copy_map, j, 0, LEFT) == 1)
			return (free_map(copy_map), 1);
	while (copy_map[0][++i + 1] != '\n')
		if (check_correct_walls(copy_map, 0, i, UP) == 1)
			return (free_map(copy_map), 1);
	i = 0;
	while (copy_map[j][++i + 1] != '\0')
		if (check_correct_walls(copy_map, j, i, DOWN) == 1)
			return (free_map(copy_map), 1);
	return (free_map(copy_map), 0);
}
