/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:00:41 by jaicastr          #+#    #+#             */
/*   Updated: 2025/08/04 01:02:29 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

t_u128	ft_hash(t_u8 *__restrict__ bytes, size_t n)
{
	t_u128	hash;
	t_u128	x;
	size_t	i;

	hash = HASH_SEED;
	i = 0;
	while (i < n)
	{
		x = __populate(*bytes++);
		x |= (x == 0) * (HASH_PRIME * ~hash);
		hash ^= ~x;
		hash *= (HASH_PRIME * ++i) * hash * x;
		hash = (hash << 13) | (hash >> (128 - 13));
	}
	return (hash);
}
