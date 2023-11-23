/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:40:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 10:29:52 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	everything(t_mlx *data, int	x, int y, int c)
{
	if (possible_end(data) == 1)
		end_prog(data, x, y, c);
	if (check_if_possible(data, c) == 1)
	{
		move_player(data, c);
		ft_printf("compteur : %d\n", data->compteur);
		data->compteur++;
	}
}

int	on_keypress(int keysym, t_mlx *data)
{
	if (data->mlx_init == NULL)
		return (1);
	if (keysym == XK_Escape)
		destroy(data);
	if (keysym == XK_Down)
		everything(data, data->perso.posx, data->perso.posy + 1, keysym);
	if (keysym == XK_Right)
		everything(data, data->perso.posx + 1, data->perso.posy, keysym);
	if (keysym == XK_Up)
		everything(data, data->perso.posx, data->perso.posy - 1, keysym);
	if (keysym == XK_Left)
		everything(data, data->perso.posx - 1, data->perso.posy, keysym);
	render_background(data);
	render_chara(data);
	return (0);
}

