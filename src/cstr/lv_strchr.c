/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lv_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:52:56 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 13:52:57 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

char	*lv_strchr(const char *s, int c)
{
	t_u64	*w;
	int		idx;
	char	*s2;

	if (!s)
		return (NULL);
	s2 = (char *)s;
	while (((t_uptr)s2) % sizeof(t_u64) != 0
		&& *s2 != (char)c && *s2 != '\0')
		s2++;
	if (*s2 == c)
		return (s2);
	w = (t_u64 *)s2;
	while (!__hasz64(w[0]))
	{
		idx = _lookup_u64(w[0], __populate((t_u8)c));
		if (idx != -1)
			return (((char *)w) + idx);
		w++;
	}
	return (NULL);
}
