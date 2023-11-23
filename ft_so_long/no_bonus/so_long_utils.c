/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:57:47 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 10:28:38 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	ft_printf("Error\n%s", rendu);
	free(vider);
	exit(EXIT_FAILURE);
}

int	destroy(t_mlx *test)
{
	mlx_destroy_image(test->mlx_init, test->perso.chara);
	mlx_destroy_image(test->mlx_init, test->mur.chara);
	mlx_destroy_image(test->mlx_init, test->vide.chara);
	mlx_destroy_image(test->mlx_init, test->door.chara);
	mlx_destroy_image(test->mlx_init, test->doorclosed.chara);
	mlx_destroy_image(test->mlx_init, test->token.chara);
	mlx_destroy_window(test->mlx_init, test->mlx_win);
	mlx_destroy_display(test->mlx_init);
	free(test->mlx_init);
	freetab(test->map->map);
	free(test->map);
	exit(0);
}
