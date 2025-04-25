/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:50:26 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 03:16:06 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"

void	*ft_recalloc(void *ptr, size_t n, size_t size)
{
	void	*p;

	if (!size)
		return (free(ptr), NULL);
	if (!ptr)
		return (ft_calloc(size, 1));
	p = ft_calloc(size, 1);
	if (!p)
		return (free(ptr), NULL);
	if (size < n)
		n = size;
	ft_memmove(p, ptr, n);
	if (ptr)
		free(ptr);
	return (p);
}
