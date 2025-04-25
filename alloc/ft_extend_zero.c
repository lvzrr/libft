/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:56:30 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/24 01:39:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"

void	*ft_extend_zero(void *ptr, size_t n, size_t size)
{
	unsigned char	*p2;

	if (size > SIZE_MAX - n)
		return (NULL);
	if (size == 0 && ptr)
		return (free(ptr), NULL);
	if (!ptr)
		return (ft_calloc(n + size, 1));
	p2 = ft_calloc(n + size, 1);
	if (!p2)
		return (NULL);
	ft_memmove(p2, ptr, n);
	return (free(ptr), p2);
}
