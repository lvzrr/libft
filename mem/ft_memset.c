/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:09:20 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:10:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mem.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	c1;

	p = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (n-- > 0)
		*p++ = c1;
	return ((void *) s);
}
