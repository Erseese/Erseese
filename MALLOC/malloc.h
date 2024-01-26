/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:49:50 by ytouihar          #+#    #+#             */
/*   Updated: 2024/01/26 13:37:01 by ytouihar         ###   ########.fr       */
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

# define BLOCK_SIZE sizeof(t_block)
# define PAGE_SIZE getpagesize()

typedef struct s_block
{
	size_t			size;
	struct s_block	*next;
	int				free;
}	t_block;

#endif