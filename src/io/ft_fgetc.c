#include "io.h"

static inline void	readbuf(t_string *store, int fd, size_t *off)
{
	ssize_t		res;

	res = read(fd, store->data, BUFSIZE);
	if (res < 0)
	{
		ft_tstr_free(store);
		*off = 0;
		return ;
	}
	store->len = res;
}

int	ft_fgetc(int fd, bool clean)
{
	static t_string	store = {0};
	static size_t	offset = {0};

	if (fd < 0)
		return (EOF);
	if (clean && store.len)
		return (ft_tstr_free(&store), offset = 0, EOF);
	if (!store.alloc_size)
	{
		store = ft_tstr_new(BUFSIZE);
		if (!store.data)
			return (EOF);
	}
	if (store.len == offset)
	{
		offset = 0;
		ft_tstr_clear(&store);
		readbuf(&store, fd, &offset);
	}
	if (store.len)
		return ((unsigned char)store.data[offset++]);
	else
		return (offset = 0, ft_tstr_free(&store), EOF);
}
