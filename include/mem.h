/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:59:36 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 19:03:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MEM_H
# define MEM_H
# include <sys/types.h>
# include <stdlib.h>
# include "alloc.h"
# include "structs.h"

void			ft_bzero(void *__restrict__ ptr, size_t n);
void			*ft_memset(void *__restrict__ s, int c, size_t n);
void			*ft_memcpy(void *__restrict__ dest,
					const void *__restrict__ src, size_t n);
void			ft_memtake(void *__restrict__ dest,
					void *__restrict__ src, size_t n);
t_u8			ft_memswap(void *__restrict__ p1,
					void *__restrict__ p2, size_t n);
t_u8			ft_memswap_extern(void *__restrict__ p1,
					void *__restrict__ p2, size_t n, void *buffer);
void			*ft_memmove(void *__restrict__ dest,
					const void *__restrict__ src, size_t n);
void			*ft_memchr(const void *__restrict__ ptr, int c, size_t n);
int				ft_memcmp(const void *__restrict__ r1,
					const void *__restrict__ r2, size_t n);
#endif
