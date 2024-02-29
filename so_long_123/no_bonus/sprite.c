/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:37:23 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/25 13:35:07 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_background(t_mlx *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->map[x] != NULL)
	{
		y = 0;
		while (game->map->map[x][y] != '\0')
		{
			if (game->map->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx_init, game->mlx_win, \
			game->mur.chara, y * WINDOWY, x * WINDOWX);
			else
				mlx_put_image_to_window(game->mlx_init, game->mlx_win, \
			game->vide.chara, y * WINDOWY, x * WINDOWX);
			y++;
		}
		x++;
	}
	return (1);
}

void	render_chara(t_mlx *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_init, game->mlx_win, \
			game->doorclosed.chara, x * 32, y * 32);
			if (game->map->map[y][x] == 'E' && possible_end(game))
				mlx_put_image_to_window(game->mlx_init, game->mlx_win, \
			game->door.chara, x * 32, y * 32);
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_init, game->mlx_win, \
			game->token.chara, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, \
	game->perso.chara, game->perso.posx * 32, game->perso.posy * 32);
}

void	check_and_free_image(t_mlx *game)
{
	if (!game->mur.chara || !game->vide.chara || !game->perso.chara \
	|| !game->token.chara || !game->door.chara || !game->doorclosed.chara)
	{
		destroy(game);
	}
}

void	createsprite(t_mlx *game)
{
	game->mur.chara = mlx_xpm_file_to_image(game->mlx_init, \
	"sprites/mur3232.xpm", &game->mur.x, &game->mur.y);
	game->vide.chara = mlx_xpm_file_to_image(game->mlx_init, \
	"sprites/vide.xpm", &game->vide.x, &game->vide.y);
	game->perso.chara = mlx_xpm_file_to_image(game->mlx_init, \
	"sprites/char.xpm", &game->perso.x, &game->perso.y);
	game->token.chara = mlx_xpm_file_to_image(game->mlx_init, \
	"sprites/token.xpm", &game->token.x, &game->token.y);
	game->door.chara = mlx_xpm_file_to_image(game->mlx_init, \
	"sprites/door.xpm", &game->door.x, &game->door.y);
	game->doorclosed.chara = mlx_xpm_file_to_image(game->mlx_init, \
	"sprites/doorclosed.xpm", &game->doorclosed.x, &game->doorclosed.y);
	check_and_free_image(game);
	render_background(game);
	render_chara(game);
}

void	init_player(t_mlx *pos)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (pos->map->map[y] != NULL)
	{
		x = 0;
		while (pos->map->map[y][x] != '\0')
		{
			if (pos->map->map[y][x] == 'P')
				pos->perso.posy = y;
			if (pos->map->map[y][x] == 'P')
				pos->perso.posx = x;
			x++;
		}
		y++;
	}
}
