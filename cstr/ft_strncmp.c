/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:05:32 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/08 11:52:37 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*w;
	unsigned char	*z;

	w = (unsigned char *)s1;
	z = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (w[i] != z[i] || !w[i] || !z[i])
			return (w[i] - z[i]);
		i++;
	}
	return (0);
}
