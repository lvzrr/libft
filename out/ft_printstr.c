/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:55:17 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/11 10:57:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printstr_fd(const char *str, int fd)
{
	unsigned int	l;

	if (!str)
	{
		return (write(fd, "(null)", 6));
	}
	l = 0;
	while (str[l])
		l += write (fd, str + l, 1);
	return ((int) l);
}
