/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:58:21 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 16:00:48 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

char	*ft_strchr(const char *haystack, int needle)
{
	unsigned int	i;

	i = 0;
	while (haystack[i] && haystack[i] != (char)needle)
		i++;
	if (haystack[i] == 0 && (char)needle != 0)
		return ((void *) 0);
	return ((char *)(haystack + i));
}
