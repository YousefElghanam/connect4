/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:47:34 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:43:56 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*tmp;
	char		*ret;

	assert(s1 != NULL);
	assert(set != NULL);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	tmp = s1 + ft_strlen(s1) - 1;
	while (tmp > s1 && ft_strchr(set, *tmp))
	{
		tmp--;
	}
	ret = malloc(tmp - s1 + 2);
	if (ret == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ret, s1, tmp - s1 + 2);
	return (ret);
}
