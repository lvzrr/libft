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

void	ft_vec_push(t_vec *vec, void *data, size_t len)
{
	void	*tmp;
	size_t	toexpand;

	if (!vec || !data)
		return ;
	if (vec->size + len > vec->alloc_size)
	{
		toexpand = (len + vec->size) - vec->alloc_size;
		tmp = ft_extend_zero(vec->data,
				vec->alloc_size * vec->sizeof_type,
				toexpand * 2 * vec->sizeof_type);
		if (!tmp)
			return ;
		vec->data = tmp;
		vec->alloc_size += toexpand * 2;
	}
	ft_memcpy(((char *)(vec->data) + (vec->size * vec->sizeof_type)),
		data, len * vec->sizeof_type);
	vec->size += len;
}
