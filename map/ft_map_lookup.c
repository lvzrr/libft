/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_lookup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:01:55 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 01:03:53 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

t_mem	*ft_map_lookup(t_map *map, size_t key)
{
	size_t	i;
	size_t	*key_ptr;

	if (!map || !map->keys.data || map->keys.size == 0)
		return (NULL);
	i = 0;
	while (i < map->keys.size)
	{
		key_ptr = (size_t *)map->keys.data;
		if (key_ptr[i] == key)
			return ((t_mem *)map->values.data + i);
		i++;
	}
	return (NULL);
}
