/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:22:22 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 18:24:25 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec.h"

void	ft_vec_clear(t_vec *vec)
{
	if (!vec || !vec->data)
		return ;
	ft_memset(vec->data, 0, vec->size * vec->sizeof_type);
	vec->size = 0;
}
