/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:16:13 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:38:29 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

static size_t	count_length(int n)
{
	if (n < -9 || n > 9)
	{
		return (1 + count_length(n / 10));
	}
	return (1);
}

static void	fill_recursive(char *cur, int n)
{
	if (n < 0)
	{
		*cur = -(n % -10) + '0';
		if (n < -9)
		{
			fill_recursive(cur - 1, n / 10);
		}
	}
	else
	{
		*cur = n % 10 + '0';
		if (n > 9)
		{
			fill_recursive(cur - 1, n / 10);
		}
	}
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*nb_str;
	size_t	pos;

	length = count_length(n);
	if (n < 0)
	{
		length++;
	}
	nb_str = malloc(length + 1);
	if (nb_str == NULL)
	{
		return (NULL);
	}
	pos = length - 1;
	fill_recursive(nb_str + pos, n);
	if (n < 0)
	{
		nb_str[0] = '-';
	}
	nb_str[length] = '\0';
	return (nb_str);
}
