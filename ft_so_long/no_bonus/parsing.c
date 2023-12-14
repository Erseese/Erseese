/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:34:04 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 10:28:43 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map_value(int i, t_map *check)
{
	while (check->map[check->l][i])
	{
		if (check->map[check->l][i] != '1' &&
				check->l == 0 && check->map[check->l][i] != '\n')
			functionerror("premiere ligne mauvaise", check);
		if (check->map[check->l][0] != '1' ||
				check->map[check->l][check->taillemap - 1] != '1')
			functionerror("erreur de mur", check);
		if (check->map[check->l][i] == 'P')
			check->player++;
		else if (check->map[check->l][i] == 'E')
			check->exit++;
		else if (check->map[check->l][i] == 'C')
			check->collectibles++;
		else if (check->map[check->l][i] == '0')
			check->vide++;
		else if (check->map[check->l][i] == '1')
			check->mur++;
		else if (check->map[check->l][i] != '\0')
			functionerror("mauvais character", check);
		i++;
	}
}

void	check_map_value(t_map *check)
{
	int	i;

	i = 0;
	if (check->l < 3)
		functionerror("pas assez de ligne", check);
	while (check->map[check->l - 1][i])
	{
		if (check->map[check->l - 1][i] != '1')
			functionerror("le mur de fin est faux", check);
		i++;
	}
	if (check->player != 1 || check->exit != 1)
		functionerror("probleme d'entree ou sortie", check);
	if ((check_sortie(check->mapbis, 'E')) != 1)
		functionerror("pathfinding faux", check);
}

int	parsing(t_map *check)
{
	int	i;
	int	len;

	i = 0;
	while (check->map[check->l] != NULL)
	{
		i = 0;
		len = (int)ft_strlen(check->map[check->l]);
		if (len != check->taillemap)
			functionerror("une ligne est differente en taille", check);
		fill_map_value(i, check);
		check->l++;
	}
	check_map_value(check);
	check_collectibles(check->maptemp, check);
	if (check->collectibles < 1)
		functionerror("manque un collectible", check);
	return (1);
}

void	check_file(char *file, t_map *test)
{
	char	*ext;
	size_t	len;

	ext = ft_strrchr(file, '.');
	len = ft_strlen(ext);
	if (len < 4)
		len = 4;
	if (!ext || ft_strncmp(ext, ".ber", len) != 0)
	{
		ft_printf("Error\n%s", "Mauvais nom de fichier");
		free(test);
		exit(EXIT_FAILURE);
	}
}

t_map	*map_create(char *fichier)
{
	t_map	*test;

	test = malloc(sizeof(t_map));

	check_file(fichier, test);
	initmap(test, fichier);
	parsing(test);
	freetab(test->mapbis);
	freetab(test->maptemp);
	return (test);
}
