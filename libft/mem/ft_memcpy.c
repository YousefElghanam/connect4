/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:23:54 by bgebetsb          #+#    #+#             */
/*   Updated: 2024/04/02 18:39:34 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	assert(dest != NULL);
	assert(src != NULL);
	if (src == dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
