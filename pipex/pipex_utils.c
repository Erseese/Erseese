/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:09:05 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/13 11:26:07 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	errorfunction(char *yey)
{
	perror(yey);
	exit (1);
}

char	*find_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_substr(envp[i], 5, 500);
			return (path);
		}
		i++;
	}
	return (0);
}

char	*check_path(t_piex piex)
{
	char	*res;
	int		i;
	char	*tmp;

	i = 0;
	while (piex.paths[i] != NULL)
	{
		tmp = ft_strjoin(piex.paths[i], "/");
		res = ft_strjoin(tmp, piex.command[0]);
		free(tmp);
		if (access(res, 0) == 0)
			return (res);
		i++;
		free(res);
	}
	return (NULL);
}

void	free_env(t_piex *piex)
{
	int	i;

	close(piex->av1);
	close(piex->av4);
	free(piex->fpath);
	i = 0;
	while (piex->paths[i] != NULL)
	{
		free(piex->paths[i]);
		i++;
	}
	free(piex->paths);
}
