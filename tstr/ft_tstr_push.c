/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:02 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 13:43:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_tstr_push(t_string *str, char c)
{
	if (!str)
		return ;
	if (str->len + 1 < str->alloc_size)
	{
		str->data[str->len++] = c;
		str->data[str->len] = 0;
		return ;
	}
	str->data = ft_extend_zero(str->data, str->alloc_size, str->alloc_size * 2);
	str->alloc_size *= 2;
	if (!str->data)
		return ;
	str->data[str->len++] = c;
	str->data[str->len] = 0;
}
