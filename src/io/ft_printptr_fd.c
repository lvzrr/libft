/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:57 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_printptr_fd(unsigned long p, int *c, int fd)
{
	if (p == 0)
	{
		write(fd, "(nil)", 5);
		*c += 5;
		return ;
	}
	if (*c == 0)
	{
		write(fd, "0x", 2);
		*c += 2;
	}
	if (p >= 16)
		ft_printptr_fd(p >> 4, c, fd);
	write(fd, &("0123456789abcdef"[p & 0xF]), 1);
	(*c)++;
}
