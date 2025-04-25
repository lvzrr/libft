/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:24:48 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/11 11:26:56 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_printnbr_fd(int n, int fd, int *len)
{
	char	o;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*len += 11;
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		*len = *len + 1;
	}
	if (n >= 10)
	{
		ft_printnbr_fd(n / 10, fd, len);
		ft_printnbr_fd(n % 10, fd, len);
	}
	else
	{
		o = (n % 10) + '0';
		*len = *len + 1;
		write(fd, &o, 1);
	}
}
