/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:22:03 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 18:21:55 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap_type	type_heap(size_t size)
{
	t_heap_type type;

	if (size <= TINY_BLOCK_SIZE)
		return (TINY);
	else if (size <= SMALL_BLOCK_SIZE)
		return (SMALL);
	else
		return (LARGE);
	return (0);
}

t_heapglobal *search_heap(t_heap_type type, size_t size)
{
	t_heapglobal *start;
	
	start = g_heaps;
	if (!start)
		return (NULL);
	while (start)
	{
		if (start->type == type && start->number_blocks_used < 100)
			return (start);
		start = start->next;
	}
	return (NULL);
}

t_heapglobal *create_heap(t_heap_type type, size_t size)
{
	t_heapglobal	*heap;
	void			*futuremmap;

	switch (type) {
    case SMALL:
		futuremmap = mmap(NULL, SMALL_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1,  0);
		break;
	case TINY:
		futuremmap = mmap(NULL, TINY_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1,  0);
		break;
	default:
		futuremmap = mmap(NULL, 0, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1,  0);
	}
	heap = (t_heapglobal *)futuremmap;
	bzero(heap, sizeof(t_heapglobal));
	heap->prev = NULL;
	heap->next = g_heaps;
	heap->type = type;
	heap->number_blocks = 100;
	heap->number_blocks_used = 0;
	create_block_struct(size, type, futuremmap, heap);
	if (g_heaps != NULL)
	{
		heap->number_heap = g_heaps->number_heap + 1;
		g_heaps->prev = heap;
	}
	else
		heap->number_heap = 1;
	g_heaps = heap;
	return (heap);
}


t_heapglobal *heap_gestion(size_t size)
{
	t_heapglobal *heap;
	t_heap_type type;

	type = type_heap(size);
	if ((heap = search_heap(type, size)) == NULL)
	{
		heap = create_heap(type, size);
		g_heaps = heap;
	}
	return (heap);
}
