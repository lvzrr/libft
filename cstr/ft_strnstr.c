/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:32:00 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 18:32:51 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	while (needle[l])
		l++;
	while (haystack[i] && (i + l) <= n)
	{
		if (!ft_strncmp(&(haystack[i]), needle, l))
			return ((char *)(&(haystack[i])));
		i++;
	}
	return ((void *) 0);
}
