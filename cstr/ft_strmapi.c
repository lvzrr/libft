/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:18:58 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/08 13:23:07 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	if (!str)
		return (NULL);
	out = malloc(ft_strlen(str) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (str[i])
	{
		out[i] = f(i, str[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
