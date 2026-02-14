/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:17:56 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:43:30 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	assert(s != NULL);
	tmp = s + ft_strlen(s);
	while (tmp >= s)
	{
		if (*tmp == (char)c)
		{
			return ((char *)tmp);
		}
		tmp--;
	}
	return (NULL);
}
