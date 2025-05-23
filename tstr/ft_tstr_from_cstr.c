/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_from_cstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:21:59 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 12:43:08 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_string	ft_tstr_from_cstr(const char *str)
{
	t_string	out;

	if (!str)
	{
		out.len = 0;
		out.alloc_size = 1;
		out.data = ft_talloc_raw(1, "(cstr->tstr)", 1);
		ft_memset(out.data, 0, 1);
	}
	else
	{
		out.len = ft_strlen(str);
		out.alloc_size = out.len + 1;
		out.data = ft_talloc_raw(out.alloc_size,
				"(cstr->tstr)", 1);
		ft_memset(out.data, 0, out.alloc_size);
		if (out.data)
			ft_memcpy(out.data, str, out.len);
	}
	return (out);
}
