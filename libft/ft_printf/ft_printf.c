/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:29:32 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/05/05 13:16:16 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	append_regular(const char **format, t_stringlist **string)
{
	size_t	i;
	char	*str;

	i = 0;
	while ((*format)[i] && (*format)[i] != '%')
		i++;
	if ((*format)[i] == '%' && (*format)[i + 1] == '\0')
		return (stringlist_clear(string), 0);
	if (i > 0)
	{
		str = ft_substr(*format, 0, i);
		if (str == NULL)
			return (stringlist_clear(string), 0);
		*string = stringlist_append(*string, str, i);
		if (*string == NULL)
			return (0);
		*format += i;
	}
	return (1);
}

void	handle_arg(t_stringlist **string, t_properties **properties,
		va_list *args)
{
	t_type	type;

	type = (*properties)->type;
	if (type == STRING)
		handle_string(string, *properties, args);
	else if (type == CHAR)
		handle_char(string, *properties, args);
	else if (type == INT || type == LONG || type == SSIZE_T)
		handle_int(string, *properties, args);
	else if (type == UNSIGNED_INT || type == UNSIGNED_LONG || type == SIZE_T)
		handle_uint(string, *properties, args);
	else if (type == PERCENT)
		handle_percent(string);
	else if ((*properties)->type == HEX_UPPER
		|| (*properties)->type == HEX_LOWER)
		handle_hex(string, *properties, args);
	else if ((*properties)->type == POINTER)
		handle_pointer(string, *properties, args);
	free((*properties)->flags);
	free(*properties);
	*properties = NULL;
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_stringlist	*string;
	t_properties	*properties;

	if (format == NULL)
		return (-1);
	if (!*format)
		return (0);
	string = NULL;
	va_start(args, format);
	while (*format)
	{
		if (!append_regular(&format, &string))
			return (va_end(args), -1);
		if (*format == '%')
		{
			properties = parse_format(&format, &args);
			if (properties == NULL)
				return (stringlist_clear(&string), va_end(args), -1);
			handle_arg(&string, &properties, &args);
			if (string == NULL)
				return (va_end(args), -1);
		}
	}
	return (va_end(args), print_string(STDOUT_FILENO, &string));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list			args;
	t_stringlist	*string;
	t_properties	*properties;

	if (format == NULL)
		return (-1);
	if (!*format)
		return (0);
	string = NULL;
	va_start(args, format);
	while (*format)
	{
		if (!append_regular(&format, &string))
			return (va_end(args), -1);
		if (*format == '%')
		{
			properties = parse_format(&format, &args);
			if (properties == NULL)
				return (stringlist_clear(&string), va_end(args), -1);
			handle_arg(&string, &properties, &args);
			if (string == NULL)
				return (va_end(args), -1);
		}
	}
	return (va_end(args), print_string(fd, &string));
}
