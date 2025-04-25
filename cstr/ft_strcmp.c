/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:25:41 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/26 12:22:16 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cstr.h"

int	ft_strcmp(const char *a, const char *b)
{
	size_t	c;

	c = 0;
	while (a[c] && b[c])
	{
		if (a[c] != b[c])
			return (a[c] - b[c]);
		c++;
	}
	return (a[c] - b[c]);
}
