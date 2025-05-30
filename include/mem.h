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

void			ft_bzero(void *ptr, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_memtake(void *dest, void *src, size_t n);
t_u8			ft_memswap(void *p1, void *p2, size_t n);
t_u8			ft_memswap_extern(void *p1, void *p2, size_t n, void *buffer);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *ptr, int c, size_t n);
int				ft_memcmp(const void *r1, const void *r2, size_t n);
#endif
