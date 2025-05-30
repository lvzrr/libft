/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:59:38 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 12:20:12 by jaicastr         ###   ########.fr       */
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

void	ft_vec_push(t_vec *vec, void *data, size_t len)
{
	void	*tmp;
	size_t	new_alloc;

	if (!vec || !data)
		return ;
	if (vec->size + len > vec->alloc_size)
	{
		new_alloc = max(vec->alloc_size * 2, vec->size + len);
		tmp = ft_extend_zero(vec->data,
				vec->alloc_size * vec->sizeof_type,
				(new_alloc - vec->alloc_size) * vec->sizeof_type);
		if (!tmp)
			return ;
		vec->data = tmp;
		vec->alloc_size = new_alloc;
	}
	ft_memcpy(((t_u8 *)(vec->data) + (vec->size * vec->sizeof_type)),
		data, len * vec->sizeof_type);
	vec->size += len;
}
