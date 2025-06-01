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

__attribute__((always_inline))
inline void	*ft_memset(void *__restrict__ s, int c, size_t n)
{
	t_u8	*p;
	t_u8	c1;

	p = (t_u8 *)s;
	c1 = (t_u8)c;
	while (n-- > 0)
		*p++ = c1;
	return ((void *) s);
}
