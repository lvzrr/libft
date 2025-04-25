/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:00:56 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 19:03:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ALLOC_H
# define ALLOC_H
# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include "mem.h"

void			*ft_calloc(size_t n, size_t size);
void			*ft_extend(void *ptr, size_t n, size_t size);
void			*ft_extend_zero(void *ptr, size_t n, size_t size);
void			*ft_realloc(void *ptr, size_t n, size_t size);
void			*ft_recalloc(void *ptr, size_t n, size_t size);
#endif
