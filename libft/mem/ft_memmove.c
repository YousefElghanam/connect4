/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:30:19 by bgebetsb          #+#    #+#             */
/*   Updated: 2024/04/03 11:33:16 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_char;
	char	*src_char;

	assert(dest != NULL);
	assert(src != NULL);
	if (src == dest)
		return (dest);
	i = 0;
	dest_char = (char *)dest;
	src_char = (char *)src;
	while (i < n)
	{
		if (dest_char > src_char)
			dest_char[n - i - 1] = src_char[n - i - 1];
		else
			dest_char[i] = src_char[i];
		i++;
	}
	return (dest_char);
}
