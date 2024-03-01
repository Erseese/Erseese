/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_side.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:25:43 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/01 18:21:13 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	find_longest_line(char **map, int *i)
{
	int	j;
	int	compteur;

	compteur = 0;
	j = 0;
	while (map[*i])
	{
		j = 0;
		while (map[*i][j] != '\n' && map[*i][j] != '\0')
			j++;
		if (compteur < j)
			compteur = j;
		*i = *i + 1;
	}
	return (compteur);
}

void	last_line_copy(char **copy_map, int index, char **map, int j)
{
	int	index_j;

	index_j = -1;
	copy_map[index] = malloc(1 + j * sizeof(char));
	while (map[index][++index_j] != '\n' && map[index][index_j])
		copy_map[index][index_j] = map[index][index_j];
	while (index_j < j)
	{
		copy_map[index][index_j] = ' ';
		index_j++;
	}
	copy_map[index][index_j] = 0;
}

char	**copy_right_with_spaces(char **map, int i, int j)
{
	char	**copy_map;
	int		index;
	int		index_j;

	index = -1;
	copy_map = malloc(sizeof(char *) * (i + 1));
	copy_map[i] = NULL;
	while (++index < i - 1)
	{
		index_j = 0;
		copy_map[index] = malloc(j + 2 * sizeof(char));
		while (map[index][index_j] != '\n' && map[index][index_j])
		{
			copy_map[index][index_j] = map[index][index_j];
			index_j++;
		}
		index_j--;
		while (++index_j < j)
			copy_map[index][index_j] = ' ';
		copy_map[index][index_j] = '\n';
		copy_map[index][index_j + 1] = '\0';
	}
	last_line_copy(copy_map, index, map, j);
	return (copy_map);
}

int	handle_right(char **copy_map)
{
	int		i;

	i = 0;
	while (copy_map[(++i + 1)])
	{
		if (copy_map[i][ft_strlen(copy_map[i]) - 1] == ' ')
		{
			if (check_correct_walls(copy_map, i, \
			ft_strlen(copy_map[i]) - 2, RIGHT) == 1)
				return (1);
		}
	}
	return (0);
}
