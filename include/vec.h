/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:57:48 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 12:19:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VEC_H
# define VEC_H

# include <stddef.h>
# include "structs.h"
# include "map.h"
# include "mem.h"

t_vec		ft_vec(size_t alloc_size, size_t sizeof_type);
void		ft_vec_push(t_vec *vec, void *data, size_t len);
void		ft_vec_free(t_vec *vec);
void		ft_vec_reserve(t_vec *v, size_t n);
void		*ft_vec_pop(t_vec *v);
void		ft_vec_clear(t_vec *vec);
void		ft_vec_fit(t_vec *vec);
void		ft_vec_insert(t_vec *v, size_t index, void *data,
				size_t len);
#endif
