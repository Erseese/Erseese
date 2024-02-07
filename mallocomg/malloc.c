/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:49:14 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 19:42:55 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	rlimitsecurity(void)
{
	struct rlimit limit;

	if (getrlimit(RLIMIT_AS, &limit) != 0)
	{
		perror("getrlimit");
		return ;
	}
	if (limit.rlim_cur == RLIM_INFINITY)
		printf("Soft limit on virtual memory: unlimited\n");
	else
		printf("Soft limit on virtual memory: %ld bytes\n", (long) limit.rlim_cur);
	if (limit.rlim_max == RLIM_INFINITY)
		printf("Hard limit on virtual memory: unlimited\n");
	else
		printf("Hard limit on virtual memory: %ld bytes\n", (long) limit.rlim_max);
}

void	*ft_malloc(size_t size)
{
	pthread_mutex_lock(&security);
	size_t			total_malloc;
	t_heapglobal 	*heap;
	t_block			*block;

	heap = heap_gestion(size);
	block = get_block(heap);
	rlimitsecurity();
	pthread_mutex_unlock(&security);
	return ((char *)block + sizeof(t_block));
}

void ft_free(void *ptr)
{
	if (!ptr)
		return;
	pthread_mutex_lock(&security);
	t_block *block_ptr = (t_block *)ptr - 1;
	block_ptr->free = 1;
	//munmap((void *)block_ptr, block_ptr->size);
	pthread_mutex_unlock(&security);
}


int	main(int argc, char **argv)
{
	//int pagesize = getpagesize(); 4096
	char *test;
	test = malloc(100 * sizeof(char));
	char *test2;
	test2 = malloc(100 * sizeof(char));
	int n = 0;
	printf("%d\n",g_heaps->number_heap);
	while (n < 15)
	{
		test[n] = '1'; 
		n++;
	}
	n = 0;
	while (n < 15)
	{
		test2[n] = '1'; 
		n++;
	}
	printf("test : %s, test2 : %s\n", test, test2);
	printf("test : %s\n", test);
}