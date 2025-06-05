/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE static inline void	b(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	size_t	i;
	t_u8	r;

	i = 0;
	r = _aligned((t_u8 *)dest, (t_u8 *)src, &i);
	while (n >= 2 && !r)
	{
		((t_u8 *)dest)[i] = ((t_u8 *)src)[i];
		((t_u8 *)dest)[i + 1] = ((t_u8 *)src)[i + 1];
		i += sizeof(t_u8) * 2;
		n -= sizeof(t_u8) * 2;
		r = _aligned((t_u8 *)dest, (t_u8 *)src, &i);
	}
	if (n > sizeof(t_u128) * 2 && r == 128)
		_copy_u128_bw((t_u8 *)dest + n, (t_u8 *)src + n, &n, &i);
	else if (n > sizeof(t_u64) * 2 && r >= 64)
		_copy_u64_bw((t_u8 *)dest + n, (t_u8 *)src + n, &n, &i);
	else if (n > sizeof(t_u32) * 32 && r >= 32)
		_copy_u32_bw((t_u8 *)dest + n, (t_u8 *)src + n, &n, &i);
	if (n > 0)
		_copy_u8_bw((t_u8 *)dest + n, (t_u8 *)src + n, &n, &i);
}

FT_INLINE_HOT inline void	*ft_memmove(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	if ((!dest || !src || dest == src) && n != 0)
		return (NULL);
	if ((t_uptr)src < (t_uptr)dest
		&& (t_uptr)src + n >= (t_uptr)dest)
		b(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
