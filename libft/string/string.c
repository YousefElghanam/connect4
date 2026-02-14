/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:47:21 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:43:57 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

t_string	*string_create(const char *input)
{
	size_t	length;

	assert(input != NULL);
	length = ft_strlen(input);
	return (string_create_len(input, length));
}

/*
 * Creates a t_string from a char array, but this one also takes the length
 * so it would also work if the original input is not terminated with \0.
 * Internally it will still be terminated with \0 for compatibility reasons
 * with other functions.
 */
t_string	*string_create_len(const char *input, size_t length)
{
	size_t		alloc;
	t_string	*string;

	assert(input != NULL);
	alloc = next_power_of_two(length);
	if (alloc < MIN_ALLOC_SIZE)
		alloc = MIN_ALLOC_SIZE;
	string = malloc(sizeof(t_string) + alloc + 1);
	if (!string)
		return (NULL);
	string->max_size = alloc;
	string->length = length;
	ft_memcpy(string->buf, input, length);
	string->buf[length] = '\0';
	return (string);
}

/*
 * Creates a duplicate of a t_string. Uses memcpy so it would also work for
 * binary strings. Length + 1 because we want to copy the \0 from the
 * original t_string as well.
 */
t_string	*string_dup(const t_string *string)
{
	t_string	*dup;

	assert(string != NULL);
	dup = malloc(sizeof(t_string) + string->max_size + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup->buf, string->buf, string->length + 1);
	dup->length = string->length;
	dup->max_size = string->max_size;
	return (dup);
}

ssize_t	string_put(const t_string *string, int fd)
{
	assert(string != NULL);
	if (string->length > 0)
		return (write(fd, string->buf, string->length));
	return (0);
}

char	*string_get_c_string(const t_string *string)
{
	char	*buf;

	assert(string != NULL);
	buf = malloc(string->length + 1);
	if (!buf)
		return (NULL);
	ft_memcpy(buf, string->buf, string->length + 1);
	return (buf);
}
