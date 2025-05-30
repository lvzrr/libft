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

t_u8	ft_memswap(void *p1, void *p2, size_t len)
{
	void	*buffer;

	if (!p1 || !p2 || !len)
		return (0);
	buffer = ft_talloc(len, "swap buffer");
	if (!buffer)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	ft_free(&buffer);
	return (1);
}

t_u8	ft_memswap_extern(void *p1, void *p2, size_t len, void *buffer)
{
	if (!p1 || !p2 || !len || !buffer)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	return (1);
}
