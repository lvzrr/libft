/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memffb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE static inline void	*_look4_u8_tmp(void *__restrict__ ptr,
	t_u8 x,
	size_t *__restrict__ n, size_t *__restrict__ i)
{
	t_u8	*d;
	int		lk;
	t_u8	r;

	r = 0;
	d = (t_u8 *) __builtin_assume_aligned(ptr, 8);
	while (*n >= sizeof(t_u8) * 2 && !r)
	{
		if (*d++ == x)
			return ((t_u8 *)d - sizeof(t_u8) + lk);
		r = _aligned((t_u8 *)ptr, NULL, i);
		if (r)
			return (NULL);
		if (*d++ == x)
			return ((t_u8 *)d - sizeof(t_u8) + lk);
		*n -= sizeof(t_u8) * 2;
		*i += sizeof(t_u8) * 2;
		r = _aligned((t_u8 *)ptr, NULL, i);
	}
	return (NULL);
}

void	*ft_memffb(const void *__restrict__ ptr,
	t_u8 x, size_t n)
{
	t_u64	mask;
	t_u8	r;
	size_t	i;
	void	*p;

	if (!ptr || n == 0)
		return (NULL);
	mask = __populate(x);
	i = 0;
	r = _aligned((t_u8 *)ptr, NULL, &i);
	if (r == 0)
	{
		p = _look4_u8_tmp((t_u8 *)ptr, mask, &n, &i);
		r = _aligned((t_u8 *)ptr, NULL, &i);
	}
	if (n >= sizeof(t_u128) * 2 && r == 128 && !p)
		p = _look4_u128_fwd((t_u8 *)ptr, mask, &n, &i);
	else if (n >= sizeof(t_u64) * 2 && r >= 64 && !p)
		p = _look4_u64_fwd((t_u8 *)ptr, mask, &n, &i);
	else if (n >= sizeof(t_u32) * 2 && r >= 32 && !p)
		p = _look4_u32_fwd((t_u8 *)ptr, (t_u32)mask, &n, &i);
	if (n > 0 && !p)
		p = _look4_u8_fwd((t_u8 *)ptr, x, &n, &i);
	return (p);
}
