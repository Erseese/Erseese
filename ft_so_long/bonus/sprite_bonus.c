/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:37:23 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 11:37:02 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	render_background(t_mlx *bg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (bg->map->map[x] != NULL)
	{
		y = 0;
		while (bg->map->map[x][y] != '\0')
		{
			if (bg->map->map[x][y] == '1')
				mlx_put_image_to_window(bg->mlx_init, bg->mlx_win, \
			bg->mur.chara, y * WINDOWY, x * WINDOWX);
			else if (bg->map->map[x][y] == 'N')
				mlx_put_image_to_window(bg->mlx_init, bg->mlx_win, \
			bg->enemy.chara, y * WINDOWY, x * WINDOWX);
			else
				mlx_put_image_to_window(bg->mlx_init, bg->mlx_win, \
			bg->vide.chara, y * WINDOWY, x * WINDOWX);
			y++;
		}
		x++;
	}
	return (1);
}

void	render_chara(t_mlx *testt, void *yes)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (testt->map->map[y] != NULL)
	{
		x = 0;
		while (testt->map->map[y][x] != '\0')
		{
			if (testt->map->map[y][x] == 'E')
				mlx_put_image_to_window(testt->mlx_init, testt->mlx_win, \
			testt->doorclosed.chara, x * 32, y * 32);
			if (testt->map->map[y][x] == 'E' && possible_end(testt))
				mlx_put_image_to_window(testt->mlx_init, testt->mlx_win, \
			testt->door.chara, x * 32, y * 32);
			else if (testt->map->map[y][x] == 'C')
				mlx_put_image_to_window(testt->mlx_init, testt->mlx_win, \
			testt->token.chara, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(testt->mlx_init, testt->mlx_win, \
	yes, testt->pos.posx * 32, testt->pos.posy * 32);
}

void	createsprite(t_mlx *test)
{
	test->mur.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/mur3232.xpm", &test->mur.x, &test->mur.y);
	test->vide.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/vide.xpm", &test->vide.x, &test->vide.y);
	test->perso.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/char.xpm", &test->perso.x, &test->perso.y);
	test->token.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/token.xpm", &test->token.x, &test->token.y);
	test->door.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/door.xpm", &test->door.x, &test->door.y);
	test->doorclosed.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/doorclosed.xpm", &test->doorclosed.x, &test->doorclosed.y);
	test->persor.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/charr.xpm", &test->persor.x, &test->persor.y);
	test->persol.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/charl.xpm", &test->persol.x, &test->persol.y);
	test->persou.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/charu.xpm", &test->persou.x, &test->persou.y);
	test->persod.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/char.xpm", &test->persod.x, &test->persod.y);
	test->enemy.chara = mlx_xpm_file_to_image(test->mlx_init, \
	"sprites/enemy.xpm", &test->enemy.x, &test->enemy.y);
	render_background(test);
	render_chara(test, test->perso.chara);
}
