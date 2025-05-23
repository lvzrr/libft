/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:56:30 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/24 01:40:08 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alloc.h"

void	*ft_extend(void *ptr, size_t n, size_t size)
{
	unsigned char	*p2;

	if (size > SIZE_MAX - n)
		return (NULL);
	if (size == 0 && ptr)
		return (ft_free(&ptr), NULL);
	if (!ptr)
		return (ft_alloc(n + size));
	p2 = ft_alloc(n + size);
	if (!p2)
		return (NULL);
	ft_memmove(p2, ptr, n);
	return (ft_free(&ptr), p2);
}
