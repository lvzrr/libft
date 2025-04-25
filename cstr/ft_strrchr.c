/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:01:43 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:05:16 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

char	*ft_strrchr(const char *haystack, int needle)
{
	size_t	l;

	l = ft_strlen(haystack);
	while (l != 0 && haystack[l] != (char)needle)
		l--;
	if (haystack[l] != (char)needle)
		return (NULL);
	return ((char *)(haystack + l));
}
