/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:35:10 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:44:10 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mem.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret;
	t_u8	*dst;
	t_u8	*sr;

	if (!dest && !src)
		return (NULL);
	ret = dest;
	dst = (t_u8 *)dest;
	sr = (t_u8 *)src;
	while (n > 0)
	{
		*dst++ = *sr++;
		n--;
	}
	return (ret);
}
