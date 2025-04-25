/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:41:19 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/08 10:52:43 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*out;

	if (!s)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	j = 0;
	while (j < len && s[start])
		out[j++] = s[start++];
	out[j] = 0;
	return (out);
}
