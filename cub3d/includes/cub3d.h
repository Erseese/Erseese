/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:02:31 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/02 15:24:45 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <errno.h>

# define UP 1
# define DOWN 3
# define LEFT 2
# define RIGHT 4
# define NORTH 5
# define SOUTH 6
# define EAST 7
# define WEST 8

typedef struct s_parse
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			**map;
	struct s_file	*init;
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				celling_red;
	int				celling_green;
	int				celling_blue;
	int				player_position;
}			t_parse;

typedef struct s_file
{
	char			*line;
	struct s_file	*next;
}	t_file;

void	get_cubfile(t_file **init, char *file);
void	free_struct(t_file *init);
t_parse	*initalizeparse(void);
void	errorfunctionparse(t_parse *parsed, t_file *init, char *message);
void	fill_struct(t_parse *parsed, t_file *init);
int		skip_number_and_spaces(int index, t_parse *parsed, t_file *init);
int		parsing_map(t_parse *parsed);
int		check_correct_walls(char **map, int x, int y, int type);
void	free_map(char **map);
int		handle_right(char **map);
int		check_inside(t_parse *parsed);
int		find_longest_line(char **map, int *i);
char	**copy_right_with_spaces(char **map, int i, int j);
int		ft_strlen_matrice(char **map);
char	**map_copy(char **map);
int		ft_inisize(t_file *lst);

#endif