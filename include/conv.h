/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 02:14:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H
# define CONV_H
# include <unistd.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_atoi_base(char *str, char *base, int base_len);
char			*ft_itoa_base(int n, char *base);
char			*ft_utoa_base(size_t n, char *base);
#endif
