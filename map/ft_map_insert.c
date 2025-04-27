/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:46:12 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 00:53:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

int	ft_map_insert(void *ptr, size_t size, t_map *map, ...)
{
	va_list		args;
	const char	*t;
	t_string	str;
	t_mem		val;

	if (!ptr || !map || map->keys.size >= map->keys.alloc_size)
		return (-1);
	if (ft_map_lookup(map, (size_t)ptr >> 4))
		return (-1);
	val.ptr = ptr;
	val.freed = 0;
	val.size = size;
	va_start(args, map);
	t = va_arg(args, const char *);
	va_end(args);
	if (!t || !*t)
		str = ft_tstr_from_cstr("(untagged)");
	else
		str = ft_tstr_from_cstr(t);
	ft_vec_push(&map->keys, &(size_t){(size_t)ptr >> 4}, 1);
	ft_vec_push(&map->values, &val, 1);
	ft_vec_push(&map->tags, &str, 1);
	return (1);
}
