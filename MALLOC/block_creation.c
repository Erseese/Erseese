/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:37:37 by ytouihar          #+#    #+#             */
/*   Updated: 2024/02/07 18:08:39 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	*get_block(t_heapglobal *heap)
{
	t_block	*block = heap->blocks;

	while (block && block->free == 0)
	{
		block = block->next;
	}
	if (block == NULL)
		return (NULL);
	heap->number_blocks_used++;
	block->free = 0;
	return (block);
}
void	create_block_struct(size_t size, t_heap_type type, void *allocated, t_heapglobal *heap)
{
	// Initialize the first block
	size_t alloc_size;

	if (type == SMALL)
		alloc_size = SMALL_BLOCK_SIZE;
	else if (type == TINY)
		alloc_size = TINY_BLOCK_SIZE;
	else
		alloc_size = size;
	heap->blocks = (t_block *)((char *)allocated + sizeof(t_heapglobal));
	heap->blocks->previous = NULL;
	heap->blocks->next = NULL;
	heap->blocks->size = 0;
	heap->blocks->free = 1;
	heap->blocks->numberblock = 1;

	t_block *current = heap->blocks;
	for (int i = 1; i < 100; i++) 
	{
		current->next = (t_block *)((char *)current + sizeof(t_block) + alloc_size);
		current->next->previous = current;
		current->next->next = NULL;
		current->next->size = 0;
		current->next->free = 1;
		current->next->numberblock = i + 1;

		current = current->next;
	}
}
