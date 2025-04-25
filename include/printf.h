/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:04:03 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:19 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

int				ft_printchar_fd(const char c, int fd);
int				ft_printstr_fd(const char *s, int fd);
void			ft_printnbr_fd(int n, int fd, int *c);
void			ft_printunbr_fd(unsigned int n, int fd, int *c);
void			ft_printptr_fd(unsigned long p, int *c, int fd);
int				ft_printf(const char *fmt, ...);
void			ft_printhex_fd(unsigned int x, const char *set, int *l, int fd);
#endif
