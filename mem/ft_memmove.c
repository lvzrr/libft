/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:51:19 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:51:23 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mem.h"

__attribute__((always_inline))
inline void	*ft_memmove(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	t_u8	*s;
	t_u8	*d;
	size_t	i;

	if (src == dest)
		return (dest);
	s = (t_u8 *)src;
	d = (t_u8 *)dest;
	i = 0;
	if (s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
