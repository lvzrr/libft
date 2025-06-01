/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_peek_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:26:08 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/30 18:29:03 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((always_inline))
__attribute__((hot))
inline void	*ft_vec_peek_last(t_vec *v)
{
	if (!v || v->size == 0)
		return (NULL);
	return ((t_u8 *)v->data + (v->size - 1)
		* v->sizeof_type);
}
