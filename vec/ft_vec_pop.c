/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:50:42 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 17:53:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

inline void	ft_vec_pop(t_vec *v)
{
	void	*ptr;

	if (!v || !v->data || v->size == 0)
		return ;
	v->size--;
	ptr = (t_u8 *)v->data + (v->size * v->sizeof_type);
	ft_bzero(ptr, v->sizeof_type);
}
