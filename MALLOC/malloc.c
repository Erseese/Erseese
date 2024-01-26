/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:49:14 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/26 15:42:35 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <unistd.h>

int	main(void)
{

	char *test = mmap(NULL, 12, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	test[123] = 'c';
	munmap(test);
	printf("t %s",test);
}

//void *mmap(void addr[.length], size_t length, int prot, int flags, int fd, off_t offset);
//mmap(NULL, size + BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
// if (atoied > 4096)
// {
// 	compteur = atoied / pagesize;
// 	atoied = atoied / (pagesize * compteur);
// }