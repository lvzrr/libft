/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _aligned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:57:01 by jaicastr          #+#    #+#             */
/*   Updated: 2025/07/03 11:57:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

inline t_u8	_aligned(const void *__restrict__ dest,
	const void *__restrict__ src, size_t *i)
{
	t_uptr	d;
	t_uptr	s;

	d = (t_uptr)((t_u8 *)dest + *i);
	s = (t_uptr)((t_u8 *)src + *i);
	if (!(d & 127)
		&& !(s & 127))
		return (128);
	if (!(d & 63)
		&& !(s & 63))
		return (64);
	if (!(d & 31)
		&& !(s & 31))
		return (32);
	return (0);
}
