/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

FT_INLINE static inline size_t	_alinger(void *__restrict__ dest,
	t_u8 o, size_t *n, t_u8 *r)
{
	size_t	x;

	x = 0;
	while (*n >= 2 && !*r)
	{
		((t_u8 *)dest)[x] = o;
		((t_u8 *)dest)[x + 1] = o;
		x += sizeof(t_u8) * 2;
		*n -= sizeof(t_u8) * 2;
		*r = _aligned((t_u8 *)dest, NULL, &x);
	}
	return (x);
}

void	*ft_memset(void *__restrict__ dest, int c, size_t n)
{
	size_t	i;
	t_u8	r;
	t_u64	x;

	if ((!dest) && n != 0)
		return (NULL);
	x = __populate(c);
	r = _aligned((t_u8 *)dest, NULL, &x);
	i = _alinger(dest, (t_u8)x, &n, &r);
	if (n >= sizeof(t_u128) * 2 && r == 128)
		_write_u128_fwd((t_u8 *)dest, x, &n, &i);
	else if (n >= sizeof(t_u64) * 2 && r >= 64)
		_write_u64_fwd((t_u8 *)dest, (t_u64)x, &n, &i);
	else if (n >= sizeof(t_u32) * 2 && r >= 32)
		_write_u32_fwd((t_u8 *)dest, (t_u32)x, &n, &i);
	if (n > 0)
		_write_u8_fwd((t_u8 *)dest, (t_u8)x, &n, &i);
	return (dest);
}
