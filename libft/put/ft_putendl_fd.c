/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:51:24 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:48:06 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

ssize_t	ft_putendl_fd(const char *s, int fd)
{
	ssize_t	ret;
	ssize_t	tmp;

	ret = ft_putstr_fd(s, fd);
	if (ret == -1)
	{
		return (-1);
	}
	tmp = ft_putchar_fd('\n', fd);
	if (tmp == -1)
	{
		return (-1);
	}
	ret += tmp;
	return (ret);
}
