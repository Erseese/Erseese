/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:49:50 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 19:54:38 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <unistd.h>
# include <strings.h>

# define BLOCK_SIZE sizeof(t_block)
# define TINY_SIZE	(4 * getpagesize())//(100 * (taille d une tiny alloc + sizeof(t_block)) + metadonnee d une t_heapglobal donc size(t_heapglobal) precalculer ca et le transferer en page
# define TINY_BLOCK_SIZE (SMALL_SIZE / (100 + sizeof(t_block)) - sizeof(t_heapglobal))
# define SMALL_SIZE	(32 * getpagesize())//(100 * (taille d une small alloc + sizeof(t_block)) + metadonnee d une t_heapglobal donc size(t_heapglobal) precalculer ca et le transferer en page
# define SMALL_BLOCK_SIZE (SMALL_SIZE / (100 + sizeof(t_block)) - sizeof(t_heapglobal))
# define LARGE_SIZE 0

typedef enum	e_heap_type {
	TINY,
	SMALL,
	LARGE
}				t_heap_type;


typedef struct	s_block
{
	struct s_block	*previous;	
	struct s_block	*next;
	int				numberblock;
	size_t			size;
	int				free;
}				t_block;

typedef struct	s_heapglobal
{
	struct s_heapglobal	*prev;
	struct s_heapglobal	*next;
	t_heap_type			type;
	t_block				*blocks;
	int					number_blocks;
	int					number_blocks_used;
	int					number_heap;
}				t_heapglobal;

extern t_heapglobal *g_heaps;
extern pthread_mutex_t security;

t_heapglobal	*heap_gestion(size_t size);
t_block			*get_block(t_heapglobal *heap);
void	create_block_struct(size_t size, t_heap_type type, void *allocated, t_heapglobal *heap);

#endif