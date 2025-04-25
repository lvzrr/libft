/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:19:57 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 16:20:55 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_tstr_free(t_string *str)
{
	if (str->data)
	{
		free(str->data);
		str->data = NULL;
	}
	str->len = 0;
	str->alloc_size = 0;
}
