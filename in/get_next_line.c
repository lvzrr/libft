/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:42:53 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/18 12:42:54 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*free_buf(char **ptr)
{
	if (!ptr || !*ptr)
		return (*ptr = NULL, NULL);
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*manage_buffer(char *buffer)
{
	char	*brkpnt;
	char	*realloc;
	size_t	newlpos;

	brkpnt = ft_strchr(buffer, '\n');
	if (!brkpnt)
	{
		realloc = NULL;
		return (free_buf(&buffer));
	}
	else
		newlpos = (brkpnt - buffer) + 1;
	if (!buffer[newlpos])
		return (free_buf(&buffer));
	realloc = ft_substr(buffer, newlpos, ft_strlen(buffer) - newlpos);
	if (!realloc && buffer)
		return (free_buf(&buffer));
	free_buf(&buffer);
	return (realloc);
}

static char	*getl(char *buffer)
{
	char	*line;
	char	*p;
	size_t	l;

	if (!buffer)
		return (NULL);
	p = ft_strchr(buffer, '\n');
	if (p)
		l = (p - buffer) + 1;
	else
		l = ft_strlen(buffer);
	line = ft_substr(buffer, 0, l);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_buffer(int fd, char *buffer)
{
	char	*tmp;
	char	*joined;
	int		bread;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free_buf(&buffer));
	bread = 1;
	while (bread > 0 && !ft_strchr(buffer, '\n'))
	{
		bread = read(fd, tmp, BUFFER_SIZE);
		if (bread > 0)
		{
			tmp[bread] = '\0';
			joined = ft_strjoin(buffer, tmp);
			if (!joined)
				return (free_buf(&tmp), free_buf(&buffer));
			free_buf(&buffer);
			buffer = joined;
		}
	}
	free_buf(&tmp);
	if (bread == -1)
		return (free_buf(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (NULL);
	}
	if (!ft_strchr(buffer, '\n'))
	{
		buffer = read_buffer(fd, buffer);
		if (!buffer || buffer[0] == '\0')
			return (free_buf(&buffer));
	}
	line = getl(buffer);
	if (!line && buffer)
		return (free_buf(&buffer));
	buffer = manage_buffer(buffer);
	return (line);
}
