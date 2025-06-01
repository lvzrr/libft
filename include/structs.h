/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:01:10 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 12:01:11 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/types.h>
# include <stdint.h>

typedef unsigned char	t_u8;
typedef uint64_t		t_u64;
typedef uint32_t		t_u32;
typedef uintptr_t		t_uptr;

typedef struct s_string
{
	size_t	len;
	size_t	alloc_size;
	char	*data;
}	t_string;

typedef struct s_vec
{
	size_t	size;
	void	*data;
	size_t	alloc_size;
	size_t	sizeof_type;
}	t_vec;

typedef struct s_mem
{
	void			*ptr;
	size_t			size;
	unsigned int	freed;
}	t_mem;

typedef struct s_map
{
	t_vec		keys;
	t_vec		values;
	t_vec		tags;
}	t_map;

typedef struct s_arena
{
	void		*next;
	void		*data;
	size_t		used;
	size_t		size;
}	t_arena;
#endif
