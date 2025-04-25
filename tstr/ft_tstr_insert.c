/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:07:42 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 04:16:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tstr.h"

void	ft_tstr_insert(t_string *str, const char *insert, size_t position)
{
	size_t	insert_len;
	size_t	new_len;

	if (!str || !str->data || !insert || position > str->len)
		return ;
	insert_len = ft_strlen(insert);
	new_len = str->len + insert_len;
	if (new_len + 1 > str->alloc_size)
		ft_tstr_reserve(str, new_len);
	ft_memmove(str->data + position + insert_len,
		str->data + position,
		str->len - position);
	ft_memcpy(str->data + position, insert, insert_len);
	str->len = new_len;
	str->data[str->len] = '\0';
}
