/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:53:51 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/12 14:08:13 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_printhex_fd(unsigned int x, const char *set, int *l, int fd)
{
	char	o;

	if (x >= 16)
		ft_printhex_fd(x >> 4, set, l, fd);
	o = set[x & 0xF];
	*l += write(fd, &o, 1);
}
