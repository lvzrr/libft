/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:25:56 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 17:37:01 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (n == 0)
		return (l);
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (l);
}
