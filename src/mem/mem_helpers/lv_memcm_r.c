/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcm_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((always_inline))
inline ssize_t	_cmp_u8(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u8) * 2)
	{
		if (((t_u8 *)dest + *i)[0]
			!= ((t_u8 *)src + *i)[0])
			return ((ssize_t)(((t_u8 *)dest + *i)[0]
				- ((t_u8 *)src + *i)[0]));
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8);
		if (((t_u8 *)dest + *i)[0]
			!= ((t_u8 *)src + *i)[0])
			return ((ssize_t)(((t_u8 *)dest + *i)[0]
				- ((t_u8 *)src + *i)[0]));
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8);
	}
	while (*n >= sizeof(t_u8))
	{
		if (((t_u8 *)dest + *i)[0]
			!= ((t_u8 *)src + *i)[0])
			return ((ssize_t)(((t_u8 *)dest + *i)[0]
				- ((t_u8 *)src + *i)[0]));
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8);
	}
	return (0);
}

__attribute__((always_inline))
inline ssize_t	_cmp_u32(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u32) * 2)
	{
		if (((t_u32 *)((t_u8 *)dest + *i))[0]
			!= ((t_u32 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u32 *)((t_u8 *)dest + *i))[0]
				- ((t_u32 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32);
		if (((t_u32 *)((t_u8 *)dest + *i))[0]
			!= ((t_u32 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u32 *)((t_u8 *)dest + *i))[0]
				- ((t_u32 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32);
	}
	while (*n >= sizeof(t_u32))
	{
		if (((t_u32 *)((t_u8 *)dest + *i))[0]
			!= ((t_u32 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u32 *)((t_u8 *)dest + *i))[0]
				- ((t_u32 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32);
	}
	return (0);
}

FT_INLINE inline ssize_t	_cmp_u64(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u64) * 2)
	{
		if (((t_u64 *)((t_u8 *)dest + *i))[0]
			!= ((t_u64 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u64 *)((t_u8 *)dest + *i))[0]
				- ((t_u64 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64);
		if (((t_u64 *)((t_u8 *)dest + *i))[0]
			!= ((t_u64 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u64 *)((t_u8 *)dest + *i))[0]
				- ((t_u64 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64);
	}
	while (*n >= sizeof(t_u64))
	{
		if (((t_u64 *)((t_u8 *)dest + *i))[0]
			!= ((t_u64 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u64 *)((t_u8 *)dest + *i))[0]
				- ((t_u64 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64);
	}
	return (0);
}

FT_INLINE inline ssize_t	_cmp_u128(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u128) * 2)
	{
		if (((t_u128 *)((t_u8 *)dest + *i))[0]
			!= ((t_u128 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u128 *)((t_u8 *)dest + *i))[0]
				- ((t_u128 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128);
		if (((t_u128 *)((t_u8 *)dest + *i))[0]
			!= ((t_u128 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u128 *)((t_u8 *)dest + *i))[0]
				- ((t_u128 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128);
	}
	while (*n >= sizeof(t_u128))
	{
		if (((t_u128 *)((t_u8 *)dest + *i))[0]
			!= ((t_u128 *)((t_u8 *)src + *i))[0])
			return ((ssize_t)(((t_u128 *)((t_u8 *)dest + *i))[0]
				- ((t_u128 *)((t_u8 *)src + *i))[0]));
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128);
	}
	return (0);
}
