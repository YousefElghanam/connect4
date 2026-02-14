/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:35:30 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:42:39 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>

/*
 * Appends a t_string to another, either by just copying its bytes (if space is
 * available), or by allocating for a new string, and replacing the original
 * string with a newly allocated one.
 *
 * Return false if malloc fails, in that case the original strings will be
 * untouched, only if increasing the allocation size is necessary and successful
 * the original will be freed.
 */
bool	string_append(t_string **string, const t_string *append)
{
	t_string	*original;
	size_t		combined_length;
	t_string	*new;

	assert(string != NULL);
	assert(*string != NULL);
	assert(append != NULL);
	original = *string;
	combined_length = original->length + append->length;
	if (combined_length <= original->max_size)
	{
		ft_memcpy(original->buf + original->length, append->buf,
			append->length);
		original->buf[combined_length] = '\0';
		original->length = combined_length;
		return (true);
	}
	new = string_join(original, append);
	if (!new)
		return (false);
	free(original);
	*string = new;
	return (true);
}

t_string	*string_join(const t_string *first, const t_string *second)
{
	size_t		combined_length;
	size_t		alloc;
	t_string	*joined;

	assert(first != NULL);
	assert(second != NULL);
	combined_length = first->length + second->length;
	alloc = next_power_of_two(combined_length);
	joined = malloc(sizeof(t_string) + alloc + 1);
	if (!joined)
		return (NULL);
	ft_memcpy(joined->buf, first->buf, first->length);
	ft_memcpy(joined->buf + first->length, second->buf, second->length + 1);
	joined->length = combined_length;
	joined->max_size = alloc;
	return (joined);
}
