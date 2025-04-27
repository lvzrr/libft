/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:38:38 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/26 23:38:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"

void	ft_free(void	**ptr)
{
	t_mem	*mem;

	if (!ptr || !*ptr)
		return ;
	if (USE_GC)
	{
		mem = ft_map_lookup(g_table,
				(size_t)(*ptr) >> 4);
		if (mem && !mem->freed && mem->ptr)
		{
			free(mem->ptr);
			mem->freed = 1;
			mem->ptr = NULL;
			mem->size = 0;
		}
		else if (!mem || mem->ptr != *ptr)
			free(*ptr);
	}
	else
		free(*ptr);
	*ptr = NULL;
}
