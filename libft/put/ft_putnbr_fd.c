/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:05:27 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:48:13 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <unistd.h>

static size_t	count_length(int n);

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	buffer[20];
	size_t	length;
	char	*cur;

	if (n < 0)
		buffer[0] = '-';
	else if (n == 0)
		return (write(fd, "0", 1));
	length = count_length(n);
	cur = buffer + length;
	while (n)
	{
		if (n < 0)
			*(--cur) = -(n % -10) + '0';
		else
			*(--cur) = n % 10 + '0';
		n /= 10;
	}
	return (write(fd, buffer, length));
}

static size_t	count_length(int n)
{
	size_t	length;

	if (n == 0)
		return (1);
	length = (n < 0);
	while (n)
	{
		length++;
		n /= 10;
	}
	return (length);
}
