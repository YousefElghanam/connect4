/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:44:36 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:42:20 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*buf;
	size_t			length;
	unsigned int	i;

	assert(s != NULL);
	assert(f != NULL);
	length = ft_strlen(s);
	buf = malloc(length + 1);
	if (buf == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
