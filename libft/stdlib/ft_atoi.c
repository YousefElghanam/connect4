/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:37:49 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 01:45:21 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	unsigned long	sum;
	int				sign;

	assert(nptr != NULL);
	sum = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		sum = sum * 10 + (*nptr - '0');
		if (sum > ((unsigned long)LONG_MAX) + (sign == -1))
			return (0 - (sign == 1));
		nptr++;
	}
	return (sum * sign);
}
