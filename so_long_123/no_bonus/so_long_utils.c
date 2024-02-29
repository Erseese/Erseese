/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:57:47 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/25 13:34:08 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	functionerror(char *rendu, t_map *vider)
{
	if (vider->map != NULL)
		freetab(vider->map);
	if (vider->mapbis != NULL)
		freetab(vider->mapbis);
	if (vider->maptemp != NULL)
		freetab(vider->maptemp);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(rendu, 2);
	free(vider);
	exit(EXIT_FAILURE);
}

int	destroy(t_mlx *game)
{
	if (game->perso.chara)
		mlx_destroy_image(game->mlx_init, game->perso.chara);
	if (game->mur.chara)
		mlx_destroy_image(game->mlx_init, game->mur.chara);
	if (game->vide.chara)
		mlx_destroy_image(game->mlx_init, game->vide.chara);
	if (game->door.chara)
		mlx_destroy_image(game->mlx_init, game->door.chara);
	if (game->doorclosed.chara)
		mlx_destroy_image(game->mlx_init, game->doorclosed.chara);
	if (game->token.chara)
		mlx_destroy_image(game->mlx_init, game->token.chara);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_init, game->mlx_win);
	if (game->mlx_init)
		mlx_destroy_display(game->mlx_init);
	free(game->mlx_init);
	freetab(game->map->map);
	free(game->map);
	exit(0);
}
