/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:06:02 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/22 14:18:29 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_open(t_piex *piex, char **argv)
{
	piex->av1 = open(argv[1], O_RDONLY);
	if (piex->av1 < 0)
		errorfunction("Infile");
	piex->av4 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (piex->av4 < 0)
	{
		close(piex->av1);
		errorfunction("Outfile");
	}
}

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (n > i)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	init_struct(t_piex *piex, char **argv, char **env)
{
	ft_memset(piex, 0, sizeof(t_piex));
	create_open(piex, argv);
	if (pipe(piex->pipefd) < 0)
	{
		free_piex(piex);
		errorfunction("Pipe");
	}
	piex->fpath = find_path(env);
	if (!piex->fpath)
	{
		free_piex(piex);
		ft_putstr_fd("pasbon init struct fpath\n", 2);
		exit(EXIT_FAILURE);
	}
	piex->paths = ft_split(piex->fpath, ':');
	if (!piex->paths)
	{
		free_piex(piex);
		ft_putstr_fd("pasbon init struct paths\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	waitpidfunction(t_piex *piex)
{
	int	pid_status;

	pid_status = 0;
	pid_status = waitpid(piex->fork, NULL, 0);
	if (pid_status == -1)
		errorfunction("waitpidfork");
	pid_status = waitpid(piex->forkt, NULL, 0);
	if (pid_status == -1)
		errorfunction("waitpidforkt");
}
