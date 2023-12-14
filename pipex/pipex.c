/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:51:17 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/13 11:25:47 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env, t_piex piex)
{
	int	i;

	i = 0;
	piex.command = ft_split(cmd, ' ');
	piex.nicecommand = check_path(piex);
	if (!piex.nicecommand)
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

void	filsl(char **argv, t_piex piex, char **env)
{
	dup2(piex.pipefd[0], STDIN_FILENO);
	close(piex.pipefd[1]);
	dup2(piex.av4, STDOUT_FILENO);
	exec(argv[3], env, piex);
	execve(piex.nicecommand, piex.command, env);
}

void	open_fils(char **argv, t_piex piex, char **env)
{
	dup2(piex.pipefd[1], STDOUT_FILENO);
	close(piex.pipefd[0]);
	dup2(piex.av1, STDIN_FILENO);
	exec(argv[2], env, piex);
	execve(piex.nicecommand, piex.command, env);
}

void	create_open(t_piex *piex, char **argv)
{
	piex->av1 = open(argv[1], O_RDONLY);
	if (piex->av1 < 0)
		errorfunction("Infile");
	piex->av4 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (piex->av4 < 0)
		errorfunction("Outfile");
}

int	main(int argc, char **argv, char **env)
{
	t_piex	piex;

	if (argc != 5)
		errorfunction("Invalid number of arguments.\n");
	create_open(&piex, argv);
	if (pipe(piex.pipefd) < 0)
		errorfunction("Pipe");
	piex.fpath = find_path(env);
	piex.paths = ft_split(piex.fpath, ':');
	piex.fork = fork();
	if (piex.fork == 0)
		open_fils(argv, piex, env);
	piex.forkt = fork();
	if (piex.forkt == 0)
		filsl(argv, piex, env);
	close(piex.pipefd[0]);
	close(piex.pipefd[1]);
	waitpid(piex.fork, NULL, 0);
	waitpid(piex.forkt, NULL, 0);
	free_env(&piex);
	return (0);
}
