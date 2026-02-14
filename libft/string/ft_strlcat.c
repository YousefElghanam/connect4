/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:03:30 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:41:15 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;

	assert(dst != NULL);
	assert(src != NULL);
	src_length = ft_strlen(src);
	if (size == 0)
	{
		return (src_length);
	}
	dst_length = ft_strlen(dst);
	if (dst_length <= size - 1)
	{
		ft_strlcpy(dst + dst_length, src, size - dst_length);
		return (src_length + dst_length);
	}
	return (src_length + size);
}
