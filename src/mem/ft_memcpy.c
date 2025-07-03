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
	while (n-- && ((t_uptr)src & 32) && ((t_uptr)dest & 32))
		*bd++ = *bs++;
	if (!((t_uptr)src & 127))
		_copy_u128_fwd(dest, src, &n);
	if (!((t_uptr)src & 63))
		_copy_u64_fwd(dest, src, &n);
	if (!((t_uptr)src & 31))
		_copy_u32_fwd(dest, src, &n);
	if (n > 0)
		_copy_u8_fwd(dest, src, &n);
	return (ret);
}
