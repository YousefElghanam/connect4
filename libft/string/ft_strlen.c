/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:09:28 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:41:49 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	assert(s != NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
