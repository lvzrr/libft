/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:50:26 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/24 01:53:38 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"

void	*ft_realloc(void *ptr, size_t n, size_t size)
{
	void	*p;

	if (!size)
		return (free(ptr), NULL);
	if (!ptr)
		return (malloc(size));
	p = malloc(size);
	if (!p)
		return (free(ptr), NULL);
	if (size < n)
		n = size;
	ft_memmove(p, ptr, n);
	if (ptr)
		free(ptr);
	return (p);
}
