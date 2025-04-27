/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:19:27 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 01:19:44 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

void	ft_map_free(t_map *map)
{
	size_t	size;
	size_t	i;

	if (!map)
		return ;
	size = map->tags.size;
	ft_vec_free(&map->keys);
	i = 0;
	while (i < size)
		ft_free(&(((t_mem *)map->values.data)[i++].ptr));
	i = 0;
	while (i < size)
		ft_tstr_free(&((t_string *)map->tags.data)[i++]);
	ft_vec_free(&map->values);
	ft_vec_free(&map->tags);
	free(map);
}
