/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:51:17 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/22 14:19:53 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env, t_piex piex)
{
	int	i;

	i = 0;
	piex.command = ft_split(cmd, ' ');
	if (piex.command == NULL)
		errorfunction("flopsplit");
	piex.nicepath = check_path(piex);
	if (!piex.nicepath)
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
	if (execve(piex.nicepath, piex.command, env) == -1)
	{
		free(piex.command);
		free(piex.nicepath);
		free_piex(&piex);
		errorfunction("flop");
	}
}

void	filsl(char **argv, t_piex piex, char **env)
{
	close(piex.pipefd[1]);
	if (dup2(piex.av4, STDOUT_FILENO) == -1)
		errorfunction("flopfilsl");
	close(piex.av4);
	if (dup2(piex.pipefd[0], STDIN_FILENO) == -1)
		errorfunction("flopfilsl");
	close(piex.pipefd[0]);
	exec(argv[3], env, piex);
}

void	open_fils(char **argv, t_piex piex, char **env)
{
	close(piex.pipefd[0]);
	if (dup2(piex.pipefd[1], STDOUT_FILENO) == -1)
		errorfunction("flopopenfils");
	close(piex.pipefd[1]);
	if (dup2(piex.av1, STDIN_FILENO) == -1)
		errorfunction("flopopenfils");
	close(piex.av1);
	exec(argv[2], env, piex);
}

int	main(int argc, char **argv, char **env)
{
	t_piex	piex;

	if (argc != 5)
		errorfunction("Invalid number of arguments.\n");
	init_struct(&piex, argv, env);
	piex.fork = fork();
	if (piex.fork == 0)
		open_fils(argv, piex, env);
	if (piex.fork == -1)
		errorfunction("flop");
	piex.forkt = fork();
	if (piex.forkt == 0)
		filsl(argv, piex, env);
	if (piex.forkt == -1)
		errorfunction("flop");
	if (piex.fork > 0)
	{
		free_piex(&piex);
		waitpidfunction(&piex);
		return (0);
	}
}
