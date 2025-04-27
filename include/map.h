/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:54:15 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/26 20:55:27 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP_H
# define MAP_H

# ifndef MAP_SIZE
#  define MAP_SIZE 256
# endif

# include "structs.h"
# include <sys/types.h>
# include <stdarg.h>
# include "vec.h"
# include "tstr.h"
# include "mem.h"

t_map			*ft_map_init(void);
int				ft_map_insert(void *ptr, size_t size, t_map *map, ...);
t_mem			*ft_map_lookup(t_map *map, size_t key);
void			ft_map_free(t_map *map);
#endif
