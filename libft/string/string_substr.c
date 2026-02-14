/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:34:32 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:34:45 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>

t_string	*string_substr(const t_string *string, size_t pos, size_t count)
{
	size_t		amount;
	size_t		alloc;
	t_string	*substr;

	assert(string != NULL);
	if (pos >= string->length)
		return (NULL);
	amount = count;
	if (string->length - pos < amount)
		amount = string->length - pos;
	alloc = next_power_of_two(amount);
	substr = malloc(sizeof(t_string) + alloc + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr->buf, string->buf + pos, amount);
	substr->buf[amount] = '\0';
	substr->length = amount;
	substr->max_size = alloc;
	return (substr);
}
