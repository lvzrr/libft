/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:57:48 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 12:19:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_VEC_H
# define FT_VEC_H
# include "alloc.h"
# include "mem.h"

typedef struct	s_vec
{
	size_t	size;
	void	*data;
	size_t	alloc_size;
	size_t	sizeof_type;
}	t_vec;

t_vec		ft_vec(size_t alloc_size, size_t sizeof_type);
void		ft_vec_push(t_vec *vec, void *data, size_t len);
void		ft_vec_free(t_vec *vec);
#endif
