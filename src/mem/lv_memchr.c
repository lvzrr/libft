/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memchr(const void *__restrict__ ptr, int c, size_t n)
{
	unsigned int	i;
	t_u8			*p;

	p = (t_u8 *)ptr;
	i = 0;
	while (i < n)
	{
		if (p[i] == (t_u8)c)
			return (p + i);
		i++;
	}
	return ((void *) 0);
}
