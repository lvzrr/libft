#include "vec.h"

void	ft_memtake(void *__restrict__ dst,
	void *__restrict__ src, size_t len)
{
	if (!dst || !src || !len)
		return ;
	ft_memmove(dst, src, len);
	ft_bzero(src, len);
}
