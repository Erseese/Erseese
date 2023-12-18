/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:39:23 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/02 12:14:22 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "../mlx/mlx.h"
# define WINDOWX 32
# define WINDOWY 32
# define RED_PIXEL 0xFF0000
# define GREENPIXEL 0x00FF00

typedef struct s_testmap
{
	int		player;
	int		exit;
	int		collectibles;
	int		mur;
	int		vide;
	int		taillemap;
	int		l;
	char	**map;
	char	**mapbis;
	char	**maptemp;
}		t_map;

typedef struct position
{
	int	posx;
	int	posy;
}				t_pos;

typedef struct perso
{
	int		x;
	int		y;
	int		collected;
	void	*chara;
}			t_youhou;

typedef struct s_vide
{
	int		x;
	int		y;
	void	*chara;
}			t_vide;

typedef struct mlx
{
	void		*mlx_init;
	void		*mlx_win;
	int			compteur;
	t_map		*map;
	t_pos		pos;
	t_youhou	perso;
	t_youhou	persol;
	t_youhou	persod;
	t_youhou	persou;
	t_youhou	persor;
	t_vide		vide;
	t_vide		token;
	t_vide		door;
	t_vide		mur;
	t_vide		enemy;
	t_vide		doorclosed;
}			t_mlx;

int		render_background(t_mlx *bg);
void	render_chara(t_mlx *testt, void *yes);
void	createsprite(t_mlx *create);
void	init_player(t_mlx *pos);

t_map	*map_create(char *fichier);
int		check_sortie(char **map, char c);
void	check_collectibles(char **map, t_map *check);
void	functionerror(char *rendu, t_map *vider);
void	initmap(t_map *map, char *file);
void	freetab(char **tab);
int		destroy(t_mlx *test);
int		possible_end(t_mlx *data);
int		check_if_possible(t_mlx *data, int c);
void	move_player(t_mlx *data, int c);
void	end_prog(t_mlx *yey, int x, int y, int keysim);
void	death(t_mlx *data, int c);
void	*everything(t_mlx *data, int x, int y, int c);
int		on_keypress(int keysym, t_mlx *data);

#endif