/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:45:38 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/01 19:13:35 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_inisize(t_file *lst)
{
	int	compteur;

	compteur = 0;
	while (lst != NULL)
	{
		compteur++;
		lst = lst->next;
	}
	return (compteur);
}


int	ft_strlen_matrice(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

int	skip_number_and_spaces(int index, t_parse *parsed, t_file *init)
{
	int	tmp;

	tmp = index;
	while (init->line[index] && init->line[index] != ',' && \
	ft_isdigit(init->line[index]))
		index++;
	if (index - tmp >= 4 || (ft_isdigit(init->line[index]) == 0 && \
	init->line[index] != ','))
		errorfunctionparse(parsed, init, "wrong rgb code");
	index++;
	while (init->line[index] && init->line[index] == ' ')
		index++;
	return (index);
}

void	errorfunctionparse(t_parse *parsed, t_file *init, char *message)
{
	int	i;

	i = -1;
	(void)init;
	free_struct(parsed->init);
	free(parsed->north);
	free(parsed->south);
	free(parsed->east);
	free(parsed->west);
	if (parsed->map)
	{
		while (parsed->map[++i])
			free(parsed->map[i]);
		free(parsed->map);
	}
	free(parsed);
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

t_parse	*initalizeparse(void)
{
	t_parse	*parsed;

	parsed = malloc(sizeof(t_parse));
	ft_memset(parsed, 0, sizeof(t_parse));
	parsed->floor_red = 0;
	parsed->floor_green = 0;
	parsed->floor_blue = 0;
	parsed->celling_red = 0;
	parsed->celling_green = 0;
	parsed->celling_blue = 0;
	parsed->player_position = 0;
	return (parsed);
}
