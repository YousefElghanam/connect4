/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:02:36 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 19:04:44 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void	init_cache(t_cache *cache, int fd);
static char	*dup_cache(t_cache *cache);
static bool	read_until_nl(char **buf, int fd);
static void	cache_leftover(t_cache *cache, char *buf);

/*
 * Modified version of GNL, returns NULL only if read() or malloc() fails. When
 * calling this after reaching EOF it would just return an empty string. Stores
 * the last file descriptor to prevent content from being mixed up. Does not
 * store the leftover from each individual fd though, only from the last one.
 */
char	*get_next_line(int fd)
{
	static t_cache	cache;
	char			*buf;

	init_cache(&cache, fd);
	buf = dup_cache(&cache);
	if (!buf)
	{
		return (NULL);
	}
	if (read_until_nl(&buf, fd))
	{
		cache_leftover(&cache, buf);
	}
	return (buf);
}

static void	init_cache(t_cache *cache, int fd)
{
	if (fd != cache->last_fd && cache->size > 0)
	{
		ft_bzero(cache->buffer, cache->size);
		cache->size = 0;
	}
	cache->last_fd = fd;
}

static char	*dup_cache(t_cache *cache)
{
	char	*buf;
	size_t	i;

	buf = malloc(cache->size + 1);
	if (!buf)
	{
		ft_putstr_fd("gnl: allocation failure\n", STDERR_FILENO);
		return (NULL);
	}
	i = 0;
	while (i < cache->size)
	{
		buf[i] = cache->buffer[i];
		cache->buffer[i] = '\0';
		i++;
	}
	buf[i] = '\0';
	cache->size = 0;
	return (buf);
}

/*
 * Calls read(BUFFER_SIZE) until a new line is found or EOF is reached
 * Returns true only if NL is found, otherwise false. Frees and sets the
 * existing buffer to NULL if there is an allocation or read error.
 * This way the get_next_line function can always return the buf directly if
 * this function returns false.
 */
static bool	read_until_nl(char **buf, int fd)
{
	char	newbuf[BUFFER_SIZE + 1];
	char	*concat;
	ssize_t	ret;

	while (!ft_strchr(*buf, '\n'))
	{
		ret = read(fd, newbuf, BUFFER_SIZE);
		if (ret == -1)
		{
			ft_putstr_fd("gnl: read error\n", STDERR_FILENO);
			return (ft_free((void **)buf), false);
		}
		else if (ret == 0)
			return (false);
		newbuf[ret] = '\0';
		concat = ft_strjoin(*buf, newbuf);
		if (!concat)
		{
			ft_putstr_fd("gnl: allocation error\n", STDERR_FILENO);
			return (ft_free((void **)buf), false);
		}
		free(*buf);
		*buf = concat;
	}
	return (true);
}

static void	cache_leftover(t_cache *cache, char *buf)
{
	char	*cur;
	size_t	leftover_size;

	cur = ft_strchr(buf, '\n') + 1;
	leftover_size = 0;
	while (*cur)
	{
		cache->buffer[leftover_size++] = *cur;
		*cur = '\0';
		cur++;
	}
	cache->size = leftover_size;
}
