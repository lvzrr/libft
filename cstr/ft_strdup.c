/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:58:50 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/07 20:01:51 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	unsigned int	n;
	char			*newstr;

	n = 0;
	while (str[n])
		n++;
	i = 0;
	newstr = (char *)malloc(n + 1);
	if (!newstr)
		return ((void *) 0);
	while (i < n)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
