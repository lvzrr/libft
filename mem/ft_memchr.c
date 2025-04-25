/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:11:33 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:13:38 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mem.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i++;
	}
	return ((void *) 0);
}
