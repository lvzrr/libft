/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borrow_tstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:05:25 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 13:12:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

const char	*ft_tstr_borrow(const t_string *str)
{
	return (str->data);
}
