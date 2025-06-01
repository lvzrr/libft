/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_popmv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:28:33 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/30 19:31:54 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

__attribute__((always_inline))
__attribute__((hot))
inline t_u8	ft_vec_popmv(void *dst, t_vec *v)
{
	if (!dst || !v || !v->alloc_size || !v->size)
		return (0);
	ft_memtake(dst, ft_vec_peek_last(v), v->sizeof_type);
	v->size--;
	return (1);
}
