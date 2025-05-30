/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:52:51 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 18:54:26 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

static inline size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_vec_insert(t_vec *v, size_t index, void *data, size_t len)
{
	void	*new;
	size_t	new_alloc;

	if (!v || !data || len == 0 || index > v->size)
		return ;
	if (v->alloc_size < v->size + len)
	{
		new_alloc = max(v->alloc_size * 2, v->size + len);
		new = ft_extend_zero(v->data, v->alloc_size * v->sizeof_type,
				(new_alloc - v->alloc_size) * v->sizeof_type);
		if (!new)
			return ;
		v->data = new;
		v->alloc_size = new_alloc;
	}
	ft_memmove((t_u8 *)v->data + (index + len) * v->sizeof_type,
		(t_u8 *)v->data + index * v->sizeof_type,
		(v->size - index) * v->sizeof_type);
	ft_memcpy((t_u8 *)v->data + index * v->sizeof_type,
		data, len * v->sizeof_type);
	v->size += len;
}
