/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_reserve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:36:35 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 00:42:52 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tstr.h"

void	ft_tstr_reserve(t_string *str, size_t n)
{
	char	*new;

	if (!str || !str->data || n == 0)
		return ;
	if (str->alloc_size >= str->len + n)
		return ;
	new = ft_extend_zero(str->data, str->alloc_size, n);
	if (!new)
		return ;
	str->data = new;
	str->alloc_size += n;
}
