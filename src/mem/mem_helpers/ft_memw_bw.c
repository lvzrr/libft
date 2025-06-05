/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memw_bw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE inline void	_copy_u8_bw(void *__restrict__ dest,
	const void *__restrict__ src, size_t *__restrict__ n,
	size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u8) * 2)
	{
		((t_u8 *)dest + *i - 2)[1] = ((t_u8 *)src + *i - 2)[1];
		*i += sizeof(t_u8);
		((t_u8 *)dest + *i - 2)[0] = ((t_u8 *)src + *i - 2)[0];
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8) * 2;
	}
	while (*n >= sizeof(t_u8) * 2)
	{
		dest = (void *)(((t_u8 *)dest) - sizeof(t_u8));
		src = (void *)(((t_u8 *)src) - sizeof(t_u8));
		((t_u8 *)dest + *i)[0] = ((t_u8 *)src + *i)[0];
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8);
	}
}

FT_INLINE inline void	_copy_u32_bw(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u32) * 2)
	{
		((t_u32 *)((t_u8 *)dest + *i) - 2)[1]
			= ((t_u32 *)((t_u8 *)src + *i) - 2)[1];
		*i += sizeof(t_u32);
		((t_u32 *)((t_u8 *)dest + *i) - 2)[0]
			= ((t_u32 *)((t_u8 *)src + *i)- 2)[0];
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32) * 2;
	}
	while (*n >= sizeof(t_u32))
	{
		((t_u32 *)((t_u8 *)dest + *i) - 2)[1]
			= ((t_u32 *)((t_u8 *)src + *i) - 2)[1];
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32);
	}
}

FT_INLINE inline void	_copy_u64_bw(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u64) * 2)
	{
		((t_u64 *)((t_u8 *)dest + *i - 2))[1]
			= ((t_u64 *)((t_u8 *)src + *i - 2))[1];
		*i += sizeof(t_u64);
		((t_u64 *)((t_u8 *)dest + *i) - 2)[0]
			= ((t_u64 *)((t_u8 *)src + *i) - 2)[0];
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		((t_u64 *)((t_u8 *)dest + *i) - 2)[0]
			= ((t_u64 *)((t_u8 *)src + *i) - 2)[0];
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64);
	}
}

FT_INLINE inline void	_copy_u128_bw(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u128) * 2)
	{
		((t_u128 *)((t_u8 *)dest + *i) - 2)[1]
			= ((t_u128 *)((t_u8 *)src + *i) - 2)[1];
		*i += sizeof(t_u128);
		((t_u128 *)((t_u8 *)dest + *i) - 2)[0]
			= ((t_u128 *)((t_u8 *)src + *i) - 2)[0];
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128) * 2;
	}
	while (*n >= sizeof(t_u128))
	{
		((t_u128 *)((t_u8 *)dest + *i) - 2)[0]
			= ((t_u128 *)((t_u8 *)src + *i) - 2)[0];
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128);
	}
}
