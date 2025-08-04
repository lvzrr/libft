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
	while (i++ < n)
	{
		x = *bytes << 8 | *bytes << 16
			| (t_u64) * bytes << 32 | (t_u128) * bytes << 64;
		hash ^= ~x * HASH_PRIME;
		hash *= hash;
		hash = (hash << 5) | (hash >> (128 - 5));
		++bytes;
	}
	return (hash);
}
