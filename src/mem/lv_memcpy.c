/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE inline size_t	_alinger(void *__restrict__ dest,
	const void *__restrict__ src, size_t *n, t_u8 *r)
{
	size_t	x;

	x = 0;
	*r = _aligned((t_u8 *)dest, (t_u8 *)src, &x);
	while (*n >= 2 && !*r)
	{
		((t_u8 *)dest)[x] = ((t_u8 *)src)[x];
		((t_u8 *)dest)[x + 1] = ((t_u8 *)src)[x + 1];
		x += sizeof(t_u8) * 2;
		*n -= sizeof(t_u8) * 2;
		*r = _aligned((t_u8 *)dest, (t_u8 *)src, &x);
	}
	return (x);
}

FT_HOT void	*ft_memcpy(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	void	*ret;
	size_t	i;
	t_u8	r;

	if ((!dest || !src || dest == src) && n != 0)
		return (NULL);
	r = 0;
	ret = dest;
	i = _alinger(dest, src, &n, &r);
	if (n >= sizeof(t_u128) * 2 && r == 128)
		_copy_u128_fwd((t_u8 *)dest, (t_u8 *)src, &n, &i);
	else if (n >= sizeof(t_u64) * 2 && r >= 64)
		_copy_u64_fwd((t_u8 *)dest, (t_u8 *)src, &n, &i);
	else if (n >= sizeof(t_u32) * 2 && r >= 32)
		_copy_u32_fwd((t_u8 *)dest, (t_u8 *)src, &n, &i);
	if (n > 0)
		_copy_u8_fwd((t_u8 *)dest, (t_u8 *)src, &n, &i);
	return (ret);
}
