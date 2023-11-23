/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:38:13 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/23 10:53:24 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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

typedef struct perso
{
	int		x;
	int		y;
	int		posx;
	int		posy;
	int		collected;
	void	*chara;
	void	*charal;
	void	*charar;
	void	*charad;
	void	*charau;
}			t_youhou;

typedef struct s_mur
{
	int		x;
	int		y;
	void	*chara;
}			t_mur;

typedef struct s_vide
{
	int		x;
	int		y;
	void	*chara;
}			t_vide;

typedef struct s_token
{
	int		x;
	int		y;
	void	*chara;
}			t_token;

typedef struct s_door
{
	int		x;
	int		y;
	void	*chara;
}			t_door;

typedef struct s_doorclose
{
	int		x;
	int		y;
	void	*chara;
}			t_doorclose;

typedef struct mlx
{
	void		*mlx_init;
	void		*mlx_win;
	int			compteur;
	t_map		*map;
	t_youhou	perso;
	t_vide		vide;
	t_token		token;
	t_door		door;
	t_mur		mur;
	t_doorclose	doorclosed;
}			t_mlx;

int		render_background(t_mlx *bg);
void	render_chara(t_mlx *testt);
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

void	everything(t_mlx *data, int x, int y, int c);
int		on_keypress(int keysym, t_mlx *data);

#endif