/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memw_fw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline void	_copy_u8_fwd(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n)
{
	t_u8	*bd;
	t_u8	*bs;

	bd = dest;
	bs = (t_u8 *)src;
	while ((*n)--)
		*bd++ = *bs++;
}

inline void	_copy_u32_fwd(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n)
{
	t_u32	*wd;
	t_u32	*ws;

	wd = dest;
	ws = (t_u32 *)src;
	while (*n >= sizeof(t_u32))
	{
		*wd++ = *ws++;
		*n -= sizeof(t_u32);
	}
}

inline void	_copy_u64_fwd(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n)
{
	t_u64	*wd;
	t_u64	*ws;

	wd = dest;
	ws = (t_u64 *)src;
	while (*n >= sizeof(t_u64))
	{
		*wd++ = *ws++;
		*n -= sizeof(t_u64);
	}
}

inline void	_copy_u128_fwd(void *__restrict__ dest,
	const void *__restrict__ src,
	size_t *__restrict__ n)
{
	t_u128	*wd;
	t_u128	*ws;

	wd = dest;
	ws = (t_u128 *)src;
	while (*n >= sizeof(t_u128))
	{
		*wd++ = *ws++;
		*n -= sizeof(t_u128);
	}
}
