/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:01:40 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/24 01:03:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tstr.h"

void	ft_tstr_clear(t_string *s)
{
	if (!s || !s->data)
		return ;
	ft_bzero(s->data, s->len);
	s->len = 0;
}
