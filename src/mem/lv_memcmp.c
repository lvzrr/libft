/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE inline ssize_t	_alinger(void *__restrict__ dest,
	const void *__restrict__ src, size_t *n, size_t *__restrict__ i)
{
	t_u8	r;

	r = _aligned((t_u8 *)dest, (t_u8 *)src, i);
	if (*n > 0 && !r)
	{
		if (((t_u8 *)dest + *i)[0] != ((t_u8 *)src + *i)[0])
			return (((t_u8 *)dest + *i)[0] - ((t_u8 *)src + *i)[0]);
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8);
		r = _aligned((t_u8 *)dest, (t_u8 *)src, i);
	}
	return (r);
}

ssize_t	ft_memcmp(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	size_t	i;
	t_u8	r;
	ssize_t	r2;
	ssize_t	r3;

	if ((!dest && !src) || n == 0 || dest == src)
		return (0);
	if ((!dest && src) || (!src && dest))
		return (-1);
	i = 0;
	r3 = 0;
	r2 = 0;
	r2 = _alinger(dest, src, &n, &i);
	if (r2 < 0)
		return (r2);
	r = (size_t)r2;
	if (n >= sizeof(t_u128) * 2 && r == 128)
		r3 = _cmp_u128((t_u8 *)dest, (t_u8 *)src, &n, &i);
	else if (n >= sizeof(t_u64) * 2 && r >= 64)
		r3 = _cmp_u64((t_u8 *)dest, (t_u8 *)src, &n, &i);
	else if (n >= sizeof(t_u32) * 2 && r >= 32)
		r3 = _cmp_u32((t_u8 *)dest, (t_u8 *)src, &n, &i);
	if (n > 0 && r3 == 0)
		r3 = _cmp_u8((t_u8 *)dest, (t_u8 *)src, &n, &i);
	return (r3);
}
