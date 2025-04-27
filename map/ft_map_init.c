/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:41:03 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 00:45:56 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

t_map	*ft_map_init(void)
{
	t_map	*map;
	void	*tmp;
	size_t	i;

	map = (t_map *)ft_talloc_raw(sizeof(t_map),
			"(map init)", 1);
	if (!map)
		return (NULL);
	map->keys = ft_vec(MAP_SIZE, sizeof(size_t));
	map->values = ft_vec(MAP_SIZE, sizeof(t_mem));
	map->tags = ft_vec(MAP_SIZE, sizeof(t_string));
	if (!map->keys.data || !map->values.data
		|| !map->tags.data)
	{
		ft_vec_free(&map->keys);
		ft_vec_free(&map->values);
		i = 0;
		while (i < map->tags.size)
			ft_tstr_free(&((t_string *)map->tags.data)[i++]);
		ft_vec_free(&map->tags);
		tmp = (void *)map;
		ft_free(&tmp);
		return (NULL);
	}
	return (map);
}
