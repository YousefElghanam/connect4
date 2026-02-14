/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:08:54 by bgebetsb          #+#    #+#             */
/*   Updated: 2024/04/02 18:23:17 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	assert(s1 != NULL);
	assert(s2 != NULL);
	if (s1 == s2)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
