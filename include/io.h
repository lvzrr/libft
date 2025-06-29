/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 20:07:03 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/29 20:07:22 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "cstr.h"
# include "mem.h"
# include "alloc.h"

char			*get_next_line(int fd);
int				ft_printchar_fd(const char c, int fd);
int				ft_printstr_fd(const char *s, int fd);
void			ft_printnbr_fd(int n, int fd, int *c);
void			ft_printunbr_fd(unsigned int n, int fd, int *c);
void			ft_printptr_fd(unsigned long p, int *c, int fd);
int				ft_printf(const char *fmt, ...);
void			ft_printhex_fd(unsigned int x, const char *set, int *l, int fd);
#endif
