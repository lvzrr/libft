/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstr_dup_tstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:07:27 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 13:07:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_tstr_dup_cstr(t_string *str)
{
	if (!str || !str->data)
		return (NULL);
	return (ft_strdup(str->data));
}
