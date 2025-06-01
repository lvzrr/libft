/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:27:15 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/30 20:31:31 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((always_inline))
inline t_u8	ft_memswap(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	size_t	i;
	t_u8	*mp1;
	t_u8	*mp2;
	t_u8	x;

	if (!p1 || !p2 || !len)
		return (0);
	i = 0;
	mp1 = (t_u8 *)p1;
	mp2 = (t_u8 *)p2;
	while (i < len)
	{
		x = mp1[i];
		mp1[i] = mp2[i];
		mp2[i++] = x;
	}
	return (1);
}
