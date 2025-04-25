/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:50:42 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 17:53:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

void	*ft_vec_pop(t_vec *v)
{
	void	*ptr;
	void	*copy;

	if (!v || !v->data || v->size == 0)
		return (NULL);
	v->size--;
	ptr = (char *)v->data + (v->size * v->sizeof_type);
	copy = ft_calloc(1, v->sizeof_type);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, ptr, v->sizeof_type);
	ft_bzero(ptr, v->sizeof_type);
	return (copy);
}
