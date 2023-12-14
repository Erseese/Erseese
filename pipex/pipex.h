/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:41:04 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/13 11:25:57 by ytouihar         ###   ########.fr       */
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
	char	*nicecommand;
	char	**command;
}	t_piex;

char	*find_path(char **envp);
char	*check_path(t_piex piex);
void	free_env(t_piex *piex);
void	errorfunction(char *yey);
int		msg(char *err);

#endif