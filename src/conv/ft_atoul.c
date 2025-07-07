#include "lft.h"

size_t	ft_atoul(const char *str)
{
	size_t		out;
	int			neg;
	size_t		i;

	out = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		out = out * 10 + (str[i++] - '0');
	return (out * neg);
}
