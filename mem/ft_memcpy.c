/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:35:10 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:44:10 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mem.h"

__attribute__((always_inline))
inline static void	_copy_u8(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u8	*d;
	t_u8	*s;

	d = (t_u8 *) dest;
	s = (t_u8 *) src;
	while (*n > 0)
	{
		*d++ = *s++;
		(*n)--;
		(*i)++;
	}
}

__attribute__((always_inline))
inline static void	_copy_u32(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u32	*d;
	t_u32	*s;

	d = (t_u32 *) dest;
	s = (t_u32 *) src;
	while (*n >= sizeof(t_u32) * 2)
	{
		*d++ = *s++;
		*d++ = *s++;
		*n -= sizeof(t_u32) * 2;
		*i += sizeof(t_u32) * 2;
	}
}

__attribute__((always_inline))
inline static void	_copy_u64(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u64	*d;
	t_u64	*s;

	d = (t_u64 *) dest;
	s = (t_u64 *) src;
	while (*n >= sizeof(t_u64) * 2)
	{
		*d++ = *s++;
		*d++ = *s++;
		*n -= sizeof(t_u64) * 2;
		*i += sizeof(t_u64) * 2;
	}
}

__attribute__((always_inline))
__attribute__((hot))
inline static t_u8	_can(void *__restrict__ dest,
	const void *__restrict__ src)
{
	int	c1;
	int	c2;

	c1 = (((t_uptr)src % sizeof(t_u64) == 0
				&& (t_uptr)dest % sizeof(t_u64) == 0));
	c2 = (((t_uptr)src % sizeof(t_u32) == 0
				&& (t_uptr)dest % sizeof(t_u32) == 0));
	if (c1)
		return (64);
	else if (c2)
		return (32);
	else
		return (0);
}

__attribute__((always_inline))
__attribute__((hot))
inline void	*ft_memcpy(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	void	*ret;
	size_t	i;
	t_u8	r;

	if ((!dest || !src || dest == src) && n != 0)
		return (NULL);
	i = 0;
	ret = dest;
	while (n > 0 && (!_can((t_u8 *)dest + i, (t_u8 *)src + i)))
	{
		((t_u8 *)dest)[i] = ((t_u8 *)src)[i];
		i++;
		n--;
	}
	r = _can((t_u8 *)dest + i, (t_u8 *)src + i);
	if (n > 0 && r == 64)
		_copy_u64((t_u8 *)dest + i,
			(t_u8 *)src + i, &n, &i);
	else if (n > 0 && r == 32)
		_copy_u32((t_u8 *)dest + i,
			(t_u8 *)src + i, &n, &i);
	if (n > 0)
		_copy_u8((t_u8 *)dest + i,
			(t_u8 *)src + i, &n, &i);
	return (ret);
}
