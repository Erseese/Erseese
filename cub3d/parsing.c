/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:46 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/01 19:15:30 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_parse(t_parse	*parsed)
{
	free(parsed->north);
	free(parsed->south);
	free(parsed->east);
	free(parsed->west);
	free_map(parsed->map);
	free(parsed);
}

int	trim_backslashn(t_file *init)
{
	t_file	*blsm;
	t_file	*tmp;

	blsm = init;
	if (!blsm)
		return (1);
	if (!blsm->next)
	{
		free(blsm->line);
		free(blsm);
		return (1);
	}
	while (blsm->next)
	{
		if (blsm->next->line[0] == '\n')
		{
			free(blsm->next->line);
			tmp = blsm->next->next;
			free(blsm->next);
			blsm->next = tmp;
		}
		else
			blsm = blsm->next;
	}
	return (0);
}

void	check_file(char *file)
{
	char	*ext;
	size_t	len;

	ext = ft_strrchr(file, '.');
	if (ext == 0)
	{
		ft_putstr_fd("Error\nMauvais nom de fichier", 1);
		exit(EXIT_FAILURE);
	}
	//printf("ext : %s\n", ext);
	len = ft_strlen(ext);
	if (len < 4)
		len = 4;
	if (!ext || ft_strncmp(ext, ".cub", len) != 0 || len == 0)
	{
		ft_putstr_fd("Error\nMauvais nom de fichier", 1);
		exit(EXIT_FAILURE);
	}
}

t_parse	*parsing(int argc, char **argv)
{
	t_file	*init;
	t_parse	*parsed;

	init = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error\n not enough arguments", 1);
	}
	check_file(argv[1]);
	get_cubfile(&init, argv[1]);
	if (trim_backslashn(init) == 1)
	{
		printf("file vide ou erreur gnl");
		exit(0);
	}
	if (ft_inisize(init) < 9)
	{
		free_struct(init);
		printf("file trop petit");
		exit(0);
	}
	parsed = initalizeparse();
	fill_struct(parsed, init);
	free_struct(init);
	return (parsed);
}

int	main(int argc, char **argv)
{
	t_parse	*parsed;

	parsed = parsing(argc, argv);
	//printf("north : %s\nsouth : %s\neast : %s\nwest : %s\nFloor: red :%d, green: %d, bleu: %d\nCelling: roge :%d, vert: %d, blue: %d\n", parsed->north, parsed->south, parsed->east, parsed->west, parsed->floor_red, parsed->floor_green, parsed->floor_blue, parsed->celling_red, parsed->celling_green, parsed->celling_blue);
	//for (int i = 0; parsed->map[i]; i++)
	//	printf("%s", parsed->map[i]);
	if (parsing_map(parsed))
		return (free_parse(parsed), 1);
	free_parse(parsed);
	return (0);
}
