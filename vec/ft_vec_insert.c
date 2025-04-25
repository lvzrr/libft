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

void	ft_vec_insert(t_vec *v, size_t index, void *data, size_t len)
{
	void	*new;

	if (!v || !data || len == 0 || index > v->size)
		return ;
	if (v->alloc_size < v->size + len)
	{
		new = ft_extend_zero(v->data, v->alloc_size * v->sizeof_type,
				len * v->sizeof_type);
		if (!new)
			return ;
		v->data = new;
		v->alloc_size += len;
	}
	ft_memmove((char *)v->data + (index + len) * v->sizeof_type,
		(char *)v->data + index * v->sizeof_type,
		(v->size - index) * v->sizeof_type);
	ft_memcpy((char *)v->data + index * v->sizeof_type,
		data, len * v->sizeof_type);
	v->size += len;
}
