/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:06:05 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:39:59 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*newstr;

	assert(s != NULL);
	length = ft_strlen(s);
	newstr = malloc(length + 1);
	if (newstr == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(newstr, s, length + 1);
	return (newstr);
}
