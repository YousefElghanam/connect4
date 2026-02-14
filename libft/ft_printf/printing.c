/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:09:50 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/05/05 13:15:27 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static int	print_loop(int fd, const char *str, ssize_t length)
{
	ssize_t	written;
	ssize_t	ret;
	ssize_t	attempt_size;

	written = 0;
	while (written < length)
	{
		attempt_size = length - written;
		if (attempt_size > 4096)
		{
			attempt_size = 4096;
		}
		ret = write(fd, str, attempt_size);
		if (ret == -1)
		{
			return (-1);
		}
		written += ret;
		str += ret;
	}
	return (written);
}

int	print_string(int fd, t_stringlist **string)
{
	char	*str;
	size_t	length;
	int		ret;

	str = stringlist_get(*string);
	length = (*string)->total_length;
	if (str == NULL || length > INT_MAX)
		return (stringlist_clear(string), -1);
	ret = print_loop(fd, str, length);
	free(str);
	return (stringlist_clear(string), ret);
}
