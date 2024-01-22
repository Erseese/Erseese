/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:41:04 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/22 14:19:42 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft_modif/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <string.h>

typedef struct s_piex
{
	int		pipefd[2];
	pid_t	fork;
	pid_t	forkt;
	int		av1;
	int		av4;
	char	**paths;
	char	*fpath;
	char	*nicepath;
	char	**command;
}	t_piex;

char	*find_path(char **envp);
char	*check_path(t_piex piex);
void	free_piex(t_piex *piex);
void	errorfunction(char *yey);
int		msg(char *err);
void	init_struct(t_piex *piex, char **argv, char **env);
void	waitpidfunction(t_piex *piex);

#endif