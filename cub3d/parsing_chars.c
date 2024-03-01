/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:37:42 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/29 12:00:52 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	fill_map(t_parse *parsed, t_file *init)
{
	t_file	*start;
	int		i;
	char	**map;

	i = 0;
	start = init;
	while (start)
	{
		i++;
		start = start->next;
	}
	map = malloc(sizeof(char *) * (i + 1));
	map[i] = 0;
	i = 0;
	while (init)
	{
		map[i] = ft_strdup(init->line);
		init = init->next;
		i++;
	}
	parsed->map = map;
}

int	fill_ceiling(t_parse *parsed, t_file *init, char direction)
{
	int	index;

	index = 0;
	while (init->line && init->line[index] == ' ')
		index++;
	index++;
	if (init->line[index - 1] == direction)
	{
		while (init->line[index] && init->line[index] == ' ')
			index++;
		parsed->celling_red = ft_atoi(&init->line[index]);
		index = skip_number_and_spaces(index, parsed, init);
		if (parsed->celling_red > 255 || parsed->celling_red < 0)
			errorfunctionparse(parsed, init, "wrong red code");
		parsed->celling_green = ft_atoi(&init->line[index]);
		if (parsed->celling_green > 255 || parsed->celling_green < 0)
			errorfunctionparse(parsed, init, "wrong green code");
		index = skip_number_and_spaces(index, parsed, init);
		parsed->celling_blue = ft_atoi(&init->line[index]);
		if (parsed->celling_blue > 255 || parsed->celling_blue < 0)
			errorfunctionparse(parsed, init, "wrong blue code");
		return (1);
	}
	return (0);
}

int	fill_floor(t_parse *parsed, t_file *init, char direction)
{
	int	index;

	index = 0;
	while (init->line && init->line[index] == ' ')
		index++;
	index++;
	if (init->line[index - 1] == direction)
	{
		while (init->line && init->line[index] == ' ')
			index++;
		parsed->floor_red = ft_atoi(&init->line[index]);
		index = skip_number_and_spaces(index, parsed, init);
		if (parsed->floor_red > 255 || parsed->floor_red < 0)
			errorfunctionparse(parsed, init, "wrong red code");
		parsed->floor_green = ft_atoi(&init->line[index]);
		if (parsed->floor_green > 255 || parsed->floor_green < 0)
			errorfunctionparse(parsed, init, "wrong green code");
		index = skip_number_and_spaces(index, parsed, init);
		parsed->floor_blue = ft_atoi(&init->line[index]);
		if (parsed->floor_blue > 255 || parsed->floor_blue < 0)
			errorfunctionparse(parsed, init, "wrong blue code");
		return (1);
	}
	return (0);
}

int	parse_direction(t_parse *parsed, t_file *init, char *dir, char **target)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (init->line && init->line[index] == ' ')
		index++;
	if (ft_strncmp(&init->line[index], dir, ft_strlen(dir)) == 0)
	{
		index += 2;
		while (init->line[index] == ' ')
			index++;
		if (*target != NULL)
			errorfunctionparse(parsed, init, "this dir already exists");
		while (init->line[index])
		{
			index++;
			len++;
		}
		*target = ft_substr(init->line, index - len, len - 1);
		if (*target == NULL)
			errorfunctionparse(parsed, init, "substr error malloc");
		return (1);
	}
	return (0);
}

void	fill_struct(t_parse *parsed, t_file *init)
{
	int	check;
	int	count;

	count = 0;
	parsed->init = init;
	while (init && count < 6)
	{
		check = 0;
		check += parse_direction(parsed, init, "NO", &parsed->north);
		check += parse_direction(parsed, init, "EA", &parsed->east);
		check += parse_direction(parsed, init, "SO", &parsed->south);
		check += parse_direction(parsed, init, "WE", &parsed->west);
		check += fill_floor(parsed, init, 'F');
		check += fill_ceiling(parsed, init, 'C');
		if (check <= 0)
			errorfunctionparse(parsed, init, "lacks something");
		count++;
		init = init->next;
	}
	fill_map(parsed, init);
}
