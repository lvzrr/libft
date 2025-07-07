#include "lft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	o;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		o = (n % 10) + '0';
		write(fd, &o, 1);
	}
}
