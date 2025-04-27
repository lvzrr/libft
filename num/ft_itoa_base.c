/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:39:07 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 10:42:38 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	_abs(int n)
{
	if (n < 0)
		return ((unsigned int)-n);
	return ((unsigned int)n);
}

static size_t	count(int n, int blen)
{
	size_t	c;

	c = 0;
	if (n < 0)
		c++;
	while (n != 0)
	{
		c++;
		n /= blen;
	}
	return (c);
}

static int	ft_lvalidate_base(char *base)
{
	char	*ptr;
	int		l;

	l = 0;
	ptr = base;
	while (*ptr++)
		l++;
	if (l < 2)
		return (-1);
	while (*base)
	{
		ptr = base + 1;
		while (*ptr)
			if (*base == *ptr++
				|| *base == '-'
				|| *base == '+')
				return (-1);
		base++;
	}
	return (l);
}

char	*ft_itoa_base(int n, char *base)
{
	int			blen;
	char		*out;
	size_t		c;

	blen = ft_lvalidate_base(base);
	if (blen == -1)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	out = ft_talloc(count(n, blen) + 1, "(itoa_base)");
	if (!out)
		return (NULL);
	c = count(n, blen);
	out[c] = 0;
	while (n != 0)
	{
		out[--c] = base[_abs(n % blen)];
		n /= blen;
	}
	if (c == 1)
		out[--c] = '-';
	return (out);
}
