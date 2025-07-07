#include "cstr.h"
#include "tstr.h"

static ssize_t	ft_find(const char *haystack, const char *needle, size_t n,
							size_t l)
{
	size_t	i;

	i = 0;
	l = 0;
	if (!*needle)
		return (0);
	if (!*haystack)
		return (-1);
	while (haystack[i] && (i + l) <= n)
	{
		if (haystack[i] == needle[0] && !ft_strncmp(&(haystack[i]), needle, l))
			return ((ssize_t) i);
		i++;
	}
	return (-1);
}

ssize_t	ft_tstr_instr(const t_string *h, const char *n)
{
	size_t	l;

	if (!h ||!h->data || !n)
		return (-1);
	l = ft_strlen(n);
	return (ft_find(ft_tstr_borrow(h), n, h->len, l));
}
