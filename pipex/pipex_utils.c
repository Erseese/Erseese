/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:09:05 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/24 15:52:48 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_env(char **envp)
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

char	*createpath(t_piex piex)
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
	return (0);
}
