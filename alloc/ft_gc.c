/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:29:01 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 04:30:33 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"
#include "printf.h"

static void	ft_gc_debug(void)
{
	t_mem		*mem;
	t_string	*str;
	size_t		i;

	i = 0;
	while (i < g_table->keys.size)
	{
		mem = &((t_mem *)g_table->values.data)[i];
		str = &((t_string *)g_table->tags.data)[i];
		ft_printf("[GC JOB] ptr: %p, size: %u, tag: %s\n",
			mem->ptr, mem->size, str->data);
		i++;
	}
}

__attribute__((destructor))
void	ft_gc(void)
{
	if (g_table)
	{
		ft_gc_debug();
		ft_map_free(g_table);
		g_table = NULL;
	}
}
