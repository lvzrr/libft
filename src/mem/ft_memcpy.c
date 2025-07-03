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

inline void	*ft_memcpy(void *__restrict__ dest,
	const void *__restrict__ src, size_t n)
{
	void	*ret;
	t_u8	*bd;
	t_u8	*bs;

	if ((!dest || !src || dest == src) && n != 0)
		return (NULL);
	ret = dest;
	bd = dest;
	bs = (t_u8 *)src;
	while (((t_uptr)src & 32) && ((t_uptr)dest & 32) && n--)
		*bd++ = *bs++;
	if (!((t_uptr)bd & 127) && !((t_uptr)bs & 127))
		_copy_u128_fwd((void **)&bd, (const void **)&bs, &n);
	if (!((t_uptr)bd & 63) && !((t_uptr)bs & 63))
		_copy_u64_fwd((void **)&bd, (const void **)&bs, &n);
	if (!((t_uptr)bd & 31) && !((t_uptr)bs & 31))
		_copy_u32_fwd((void **)&bd, (const void **)&bs, &n);
	if (n > 0)
		_copy_u8_fwd((void **)&bd, (const void **)&bs, &n);
	return (ret);
}
