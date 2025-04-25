/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_pushstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:02 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 13:52:46 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	_append(char *dest, const char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[start + i] = '\0';
}

void	ft_tstr_pushstr(t_string *str, const char *s)
{
	size_t	len;
	size_t	needed;
	char	*new_data;

	if (!str || !s)
		return ;
	len = ft_strlen(s);
	needed = str->len + len + 1;
	if (needed > str->alloc_size)
	{
		new_data = ft_extend_zero(str->data, str->alloc_size,
				(needed - str->alloc_size) * 2);
		if (!new_data)
			return ;
		str->data = new_data;
		str->alloc_size = needed;
	}
	_append(str->data, s, str->len);
	str->len += len;
}
