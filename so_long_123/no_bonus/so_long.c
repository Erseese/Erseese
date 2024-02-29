/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:46 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/25 13:33:41 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	possible_end(t_mlx *data)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	x = 0;
	count = 0;
	while (data->map->map[x] != NULL)
	{
		y = 0;
		while (data->map->map[x][y] != '\0')
		{
			if (data->map->map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	check_if_possible(t_mlx *data, int c)
{
	int	x;
	int	y;

	x = data->perso.posx;
	y = data->perso.posy;
	if (c == XK_Down)
	{
		if (data->map->map[y + 1][x] == '1' || data->map->map[y + 1][x] == 'E')
			return (0);
	}
	else if (c == XK_Up)
	{
		if (data->map->map[y - 1][x] == '1' || data->map->map[y - 1][x] == 'E')
			return (0);
	}
	else if (c == XK_Left)
	{
		if (data->map->map[y][x - 1] == '1' || data->map->map[y][x - 1] == 'E')
			return (0);
	}
	else if (c == XK_Right)
		if (data->map->map[y][x + 1] == '1' || data->map->map[y][x + 1] == 'E')
			return (0);
	return (1);
}

void	move_player(t_mlx *data, int c)
{
	if (c == XK_Down)
	{
		data->map->map[data->perso.posy][data->perso.posx] = '0';
		data->perso.posy++;
		data->map->map[data->perso.posy][data->perso.posx] = 'P';
	}
	else if (c == XK_Up)
	{
		data->map->map[data->perso.posy][data->perso.posx] = '0';
		data->perso.posy--;
		data->map->map[data->perso.posy][data->perso.posx] = 'P';
	}
	else if (c == XK_Left)
	{
		data->map->map[data->perso.posy][data->perso.posx] = '0';
		data->perso.posx--;
		data->map->map[data->perso.posy][data->perso.posx] = 'P';
	}
	else if (c == XK_Right)
	{
		data->map->map[data->perso.posy][data->perso.posx] = '0';
		data->perso.posx++;
		data->map->map[data->perso.posy][data->perso.posx] = 'P';
	}
}

void	end_prog(t_mlx *yey, int x, int y, int keysim)
{
	if (yey->map->map[y][x] == 'E')
	{
		move_player(yey, keysim);
		destroy(yey);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	game;
	t_map	*map;

	if (argc != 2)
		return (ft_putstr_fd("Error\nil manque la map", 2), 0);
	map = map_create(argv[1]);
	if (map == NULL)
		return (0);
	game.map = map;
	game.mlx_init = mlx_init();
	if (game.mlx_init == NULL)
		return (0);
	init_player(&game);
	game.mlx_win = mlx_new_window(game.mlx_init, WINDOWX * game.map->taillemap, \
		WINDOWY * game.map->l + 1, "coucou");
	if (game.mlx_win == NULL)
		return (free(game.mlx_init), 1);
	game.compteur = 0;
	createsprite(&game);
	mlx_hook(game.mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(game.mlx_win, DestroyNotify, StructureNotifyMask, &destroy, &game);
	mlx_loop(game.mlx_init);
	return (0);
}
