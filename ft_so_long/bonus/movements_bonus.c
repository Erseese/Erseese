/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:40:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/02 12:13:45 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	death(t_mlx *data, int c);

void	*everything(t_mlx *data, int x, int y, int c)
{
	if (possible_end(data) == 1)
		end_prog(data, x, y, c);
	if (check_if_possible(data, c) == 1)
	{
		death(data, c);
		move_player(data, c);
		data->compteur++;
		printf("compteur : %d\n", data->compteur);
	}
	if (c == XK_Down)
		return (data->persod.chara);
	if (c == XK_Right)
		return (data->persor.chara);
	if (c == XK_Up)
		return (data->persou.chara);
	if (c == XK_Left)
		return (data->persol.chara);
	return (0);
}

void	death(t_mlx *data, int c)
{
	if (c == XK_Down)
		data->pos.posy++;
	else if (c == XK_Up)
		data->pos.posy--;
	else if (c == XK_Left)
		data->pos.posx--;
	else if (c == XK_Right)
		data->pos.posx++;
	if (data->map->map[data->pos.posy][data->pos.posx] == 'N')
	{
		ft_printf("lose dommage chef\n");
		destroy(data);
	}
}

void	print_move(t_mlx *data)
{
	char	*move;

	move = ft_itoa(data->compteur, 10);
	mlx_string_put(data->mlx_init, data->mlx_win, 0, WINDOWX, 0, "Move :");
	mlx_string_put(data->mlx_init, data->mlx_win, 42, WINDOWX, 0, move);
	free(move);
}

int	on_keypress(int keysym, t_mlx *data)
{
	void	*yes;

	yes = 0;
	if (data->mlx_init == NULL)
		return (1);
	else if (keysym == XK_Escape)
	{
		destroy(data);
	}
	else if (keysym == XK_Down)
		yes = everything(data, data->pos.posx, data->pos.posy + 1, keysym);
	else if (keysym == XK_Right)
		yes = everything(data, data->pos.posx + 1, data->pos.posy, keysym);
	else if (keysym == XK_Up)
		yes = everything(data, data->pos.posx, data->pos.posy - 1, keysym);
	else if (keysym == XK_Left)
		yes = everything(data, data->pos.posx - 1, data->pos.posy, keysym);
	else
		return (0);
	render_background(data);
	render_chara(data, yes);
	print_move(data);
	return (0);
}
