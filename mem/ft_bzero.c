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

__attribute__((always_inline))
inline void	ft_bzero(void *__restrict__ ptr, size_t n)
{
	t_u8	*p;

	if (n == 0)
		return ;
	p = (t_u8 *) ptr;
	while (n > 0)
		p[--n] = 0;
}
