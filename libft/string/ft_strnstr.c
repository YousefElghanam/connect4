/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:19:19 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:43:09 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include <stddef.h>

static size_t	get_min(size_t nb1, size_t nb2)
{
	if (nb2 < nb1)
	{
		return (nb2);
	}
	else
	{
		return (nb1);
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;
	size_t	i;
	size_t	j;

	assert(big != NULL);
	assert(little != NULL);
	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if ((big == NULL && len == 0) || little_len > big_len)
		return (NULL);
	i = 0;
	while (len > 0 && i < get_min(big_len, len))
	{
		j = 0;
		while (big[i + j] == little[j] && j < little_len && i + j < len)
		{
			if (++j == little_len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
