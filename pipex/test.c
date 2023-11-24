/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:03:38 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/24 11:58:33 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//	Fonction utilitaire pour écrire
void	writestr(int fd, const char *str)
{
	write(fd, str, strlen(str));
}

//	Main
int	main(void)
{
	int	pipefd[2];  // Stocke les fd du pipe :
			    //  - pipefd[0] : lecture seule
			    //  - pipefd[1] : écriture seule
	pid_t	pid;	// Stocke le retour de fork
	char	buf;	// Stocke la lecture de read

//	Crée un pipe. En cas d'échec on arrête tout
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
//	Crée un processus fils
	pid = fork();
	if (pid == -1) // Echec, on arrête tout
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) // Processus fils
	{
	//	Ferme le bout d'écriture inutilisé
		close(pipefd[1]);
		writestr(STDOUT_FILENO, "Fils : Quel est le secret dans ce pipe ?\n");
		writestr(STDOUT_FILENO, "Fils : \"");
	//	Lit les caractères dans le pipe un à un
		while (read(pipefd[0], &buf, 1) > 0)
		{
			// Écrit le caractère lu dans la sortie standard
			write(STDOUT_FILENO, &buf, 1);
		}
		writestr(STDOUT_FILENO, "\"\n");
		writestr(STDOUT_FILENO, "Fils : Ohlala ! Je vais voir mon pere.\n");
	//	Ferme le bout de lecture
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
	else	// Processus père
	{
	//	Ferme le bout de lecture inutilisé
		close(pipefd[0]);
		writestr(STDOUT_FILENO, "Pere : J'ecris un secret dans le pipe...\n");
	//	Écrit dans le bout d'écriture du pipe
		writestr(pipefd[1], "\e[33mJe suis ton pere mwahahaha!\e[0m");
	//	Ferme le bout d'ecriture (lecteur verra EOF)
		close(pipefd[1]);
	//	Attend la terminaison du fils
		wait(NULL);
		writestr(STDOUT_FILENO, "Pere : Salut mon fils !\n");
		exit(EXIT_SUCCESS);
	}
}