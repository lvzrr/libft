/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:27:22 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 17:33:26 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

void	ft_vec_reserve(t_vec *v, size_t n)
{
	void	*new;

	if (!v || !n || n <= v->alloc_size)
		return ;
	new = ft_extend_zero(v->data, v->alloc_size * v->sizeof_type,
			n * v->sizeof_type);
	if (!new)
		return ;
	v->data = new;
	v->alloc_size += n;
}
