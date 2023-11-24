/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:51:17 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/24 16:01:43 by ytouihar         ###   ########.fr       */
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

void	exec(char *argv, char **env, t_piex piex)
{
	int	i;

	i = 0;
	piex.command = ft_split(argv, ' ');
	piex.nicecommand = createpath(piex);
	if (piex.nicecommand == NULL)
	{	
		while (piex.command[i] != NULL)
		{
			free(piex.command[i]);
			i++;
		}
		free(piex.command);
		msg("Command not found\n");
		exit(1);
	}
	execve(piex.nicecommand, piex.command, env);
}

void	pere(char **argv, t_piex piex, char **env)
{
	dup2(piex.pipefd[0], STDIN_FILENO);
	close(piex.pipefd[1]);
	dup2(piex.av4, STDOUT_FILENO);
	exec(argv[3], env, piex);
	close(piex.pipefd[0]);
}

void	open_fils(char **argv, t_piex piex, char **env)
{
	dup2(piex.pipefd[1], STDOUT_FILENO);
	close(piex.pipefd[0]);
	dup2(piex.av1, STDIN_FILENO);
	exec(argv[2], env, piex);
	close(piex.pipefd[1]);
}

int	main(int argc, char **argv, char **env)
{
	t_piex	piex;
	int		i;

	if (argc != 5)
		errorfunction("Invalid number of arguments.\n");
	piex.av1 = open(argv[1], O_RDONLY);
	if (piex.av1 < 0)
		errorfunction("Infile");
	piex.av4 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (piex.av4 < 0)
		errorfunction("Outfile");
	if (pipe(piex.pipefd) < 0)
		errorfunction("Pipe");
	piex.fork = fork();
	if (piex.fork == -1)
		errorfunction("Fork");
	piex.fpath = find_env(env);
	piex.paths = ft_split(piex.fpath, ':');
	if (piex.fork == 0)
		open_fils(argv, piex, env);
	waitpid(piex.fork, NULL, 0);
	pere(argv, piex, env);
	close(piex.av1);
	close(piex.av4);
	free(piex.fpath);
	i = 0;
	while (piex.paths[i] != NULL)
	{
		free(piex.paths[i]);
		i++;
	}
	free(piex.paths);
}
