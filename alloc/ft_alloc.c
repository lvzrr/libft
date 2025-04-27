/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:37:08 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/26 23:37:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"

t_map	*g_table;

void	*ft_alloc(size_t size)
{
	return (ft_talloc(size, NULL));
}

void	*ft_talloc(size_t size, const char *t)
{
	void		*new_alloc;

	new_alloc = malloc(size);
	if (!new_alloc)
		return (NULL);
	if (USE_GC)
	{
		if (!g_table)
			g_table = ft_map_init();
		if (!t || !*t)
			t = "(untagged)";
		ft_map_insert(new_alloc, size, g_table, t);
	}
	return (new_alloc);
}

void	*ft_talloc_raw(size_t size, const char *t)
{
	void		*new_alloc;

	if (!size)
		return (NULL);
	new_alloc = malloc(size);
	if (!new_alloc)
		return (NULL);
	if (USE_GC)
	{
		if (!t || !*t)
			t = "(untagged)";
		ft_map_insert(new_alloc, size, g_table, t);
	}
	return (new_alloc);
}
