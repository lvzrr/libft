/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:16:37 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:34:18 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mem.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*p;

	if (n == 0)
		return ;
	p = (unsigned char *) ptr;
	while (n > 0)
		p[--n] = 0;
}
