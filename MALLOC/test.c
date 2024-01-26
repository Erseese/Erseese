#include "malloc.h"

static pthread_mutex_t security = PTHREAD_MUTEX_INITIALIZER;
static t_block *db = NULL;

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

void	*ft_mymalloc(size_t size)
{
	pthread_mutex_lock(&security);
	size_t total_malloc;
	int nb_page = 0;
	t_block *blsm;

	total_malloc = size + BLOCK_SIZE;
	rlimitsecurity();
	if (total_malloc > PAGE_SIZE)
	{
		nb_page = (total_malloc + PAGE_SIZE - 1) / PAGE_SIZE;
		total_malloc = nb_page * PAGE_SIZE;
	}
	if (db != NULL)
	{
		blsm = db; //credit emilie
		while (blsm->next != NULL && blsm->free == 0)
			blsm = blsm->next;
		if (blsm->free == 0)
		{
			printf("test\n");
			printf("%zu\n", total_malloc);
			blsm->next = mmap(NULL, total_malloc, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
			if (blsm->next == MAP_FAILED)
				return NULL;
			blsm = blsm->next;
			blsm->size = total_malloc - BLOCK_SIZE;
			blsm->free = 0;
			blsm->next = NULL;
		}
		else
		{
			blsm->free = 0;
			blsm = mmap(NULL, total_malloc, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
			if (blsm == MAP_FAILED)
				return NULL;
			blsm->size = total_malloc - BLOCK_SIZE;
			blsm->free = 0;
			blsm->next = NULL;
		}
		pthread_mutex_unlock(&security);
		return (blsm + 1);
	}
	else
	{
		printf("premiere allocation\n");
		db = mmap(NULL, (total_malloc), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (db == MAP_FAILED)
			return NULL;
		db->size = total_malloc - BLOCK_SIZE;
		db->free = 0;
		db->next = NULL;
	}
	pthread_mutex_unlock(&security);
	return (db + 1);
}

void ft_myfree(void *ptr)
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
	char *test = ft_mymalloc(12 * sizeof(char));
	ft_myfree(test);
	char *test1 = ft_mymalloc(12 * sizeof(char));
	char *test2 = ft_mymalloc(12 * sizeof(char));
	int n = 0;
	while (n < 1002)
	{
		test[n] = '1'; 
		n++;
	}
	test[n] = 0;
	n = 0;
	while (n < 13)
	{
		test1[n] = n + '0'; 
		n++;
	}
	test1[n] = 0;
	n = 0;
	while (n < 15)
	{
		test2[n] = '1'; 
		n++;
	}
	test2[n] = 0;
	printf("test : %s, test1 : %s, test2 : %s\n", test, test1, test2);
}