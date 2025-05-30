/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:32:46 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/30 19:33:09 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	ft_memtake(void *dst, void *src, size_t len)
{
	if (!dst || !src || !len)
		return ;
	ft_memcpy(dst, src, len);
	ft_bzero(src, len);
}
