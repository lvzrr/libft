/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:01:44 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 19:03:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef NUMS_H
# define NUMS_H
# include <unistd.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_atoi_base(char *str, char *base, int base_len);
char			*ft_itoa_base(int n, char *base);
char			*ft_utoa_base(size_t n, char *base);
#endif
