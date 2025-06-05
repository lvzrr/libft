/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memst_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE inline void	_write_u8_fwd(void *__restrict__ dest,
	t_u8 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u8) * 2)
	{
		((t_u8 *)dest + *i)[0] = x;
		*i += sizeof(t_u8);
		((t_u8 *)dest + *i)[0] = x;
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8) * 2;
	}
	while (*n > 0)
	{
		((t_u8 *)dest + *i)[0] = x;
		*i += sizeof(t_u8);
		*n -= sizeof(t_u8);
	}
}

FT_INLINE inline void	_write_u32_fwd(void *__restrict__ dest,
	t_u32 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u32) * 2)
	{
		((t_u32 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u32);
		((t_u32 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32) * 2;
	}
	while (*n >= sizeof(t_u32))
	{
		((t_u32 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u32);
		*n -= sizeof(t_u32);
	}
}

inline void	_write_u64_fwd(void *__restrict__ dest,
	t_u64 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u64) * 2)
	{
		((t_u64 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u64);
		((t_u64 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64) * 2;
	}
	while (*n >= sizeof(t_u64))
	{
		((t_u64 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u64);
		*n -= sizeof(t_u64);
	}
}

__attribute__((always_inline))
inline void	_write_u128_fwd(void *__restrict__ dest,
	t_u128 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	while (*n >= sizeof(t_u128) * 2)
	{
		((t_u128 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u128);
		((t_u128 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128) * 2;
	}
	while (*n >= sizeof(t_u128))
	{
		((t_u128 *)((t_u8 *)dest + *i))[0] = x;
		*i += sizeof(t_u128);
		*n -= sizeof(t_u128);
	}
}
