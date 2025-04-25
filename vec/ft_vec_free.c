/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:03:13 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 12:20:11 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

void	ft_vec_free(t_vec *v)
{
	if (!v)
		return ;
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->alloc_size = 0;
	v->sizeof_type = 0;
}
