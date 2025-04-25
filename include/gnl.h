/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:04:31 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "cstr.h"
# include "mem.h"
# include "alloc.h"

char			*get_next_line(int fd);
#endif 
