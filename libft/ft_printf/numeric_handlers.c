/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:14:07 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:46:59 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	handle_int(t_stringlist **string, t_properties *properties,
		va_list *args)
{
	char		*str;
	long long	num;

	if (properties->type == INT)
	{
		num = va_arg(*args, int);
	}
	else if (properties->type == LONG)
	{
		num = va_arg(*args, long);
	}
	else
	{
		num = va_arg(*args, ssize_t);
	}
	str = ft_itoa_printf(num, properties);
	if (str != NULL)
	{
		*string = stringlist_append(*string, str, ft_strlen(str));
	}
}

void	handle_uint(t_stringlist **string, t_properties *properties,
		va_list *args)
{
	char				*str;
	unsigned long long	num;
	t_chars				c;

	c.charset = "0123456789";
	c.prefix = NULL;
	if (properties->type == UNSIGNED_INT)
	{
		num = va_arg(*args, unsigned int);
	}
	else if (properties->type == UNSIGNED_LONG)
	{
		num = va_arg(*args, unsigned long);
	}
	else
	{
		num = va_arg(*args, size_t);
	}
	str = ft_itoa_base(num, properties, c);
	if (str != NULL)
	{
		*string = stringlist_append(*string, str, ft_strlen(str));
	}
}

void	handle_hex(t_stringlist **string, t_properties *properties,
		va_list *args)
{
	char			*str;
	unsigned int	num;
	t_chars			c;

	num = va_arg(*args, unsigned int);
	c.charset = "0123456789abcdef";
	c.prefix = NULL;
	if (properties->type == HEX_UPPER)
	{
		c.charset = "0123456789ABCDEF";
		if (properties->flags[5])
			c.prefix = "0X";
	}
	else if (properties->flags[5])
		c.prefix = "0x";
	str = ft_itoa_base(num, properties, c);
	if (str != NULL)
	{
		*string = stringlist_append(*string, str, ft_strlen(str));
	}
}

void	handle_nil(t_stringlist **string, t_properties *prop)
{
	int		startpos;
	int		length;
	char	*str;

	length = 5;
	if (prop->width > 5)
		length = prop->width;
	str = malloc(length);
	if (str != NULL)
	{
		ft_memset(str, ' ', length);
		startpos = 0 + (!(prop->flags[1])) * (length - 5);
		ft_memcpy(str + startpos, "(nil)", 5);
		*string = stringlist_append(*string, str, length);
	}
}

void	handle_pointer(t_stringlist **string, t_properties *prop, va_list *args)
{
	char	*str;
	void	*ptr;
	t_chars	c;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		handle_nil(string, prop);
	else
	{
		c.charset = "0123456789abcdef";
		c.prefix = "0x";
		str = ft_itoa_base((size_t)ptr, prop, c);
		if (str != NULL)
		{
			*string = stringlist_append(*string, str, ft_strlen(str));
		}
	}
}
