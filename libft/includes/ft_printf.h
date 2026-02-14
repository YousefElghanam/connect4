/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:36:25 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 15:30:54 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stringlist.h"
# include <stdarg.h>
# include <stddef.h>

typedef enum e_type
{
	STRING = 0,
	CHAR = 1,
	INT = 2,
	UNSIGNED_INT = 3,
	LONG = 4,
	UNSIGNED_LONG = 5,
	SSIZE_T = 6,
	SIZE_T = 7,
	PERCENT = 8,
	HEX_LOWER = 9,
	HEX_UPPER = 10,
	POINTER = 11,
	OTHER = 12
}				t_type;

typedef struct s_properties
{
	t_type		type;
	char		*flags;
	int			width;
	int			precision;
}				t_properties;

typedef struct s_chars
{
	char		*charset;
	char		*prefix;
}				t_chars;

char			*ft_itoa_base(unsigned long long n, t_properties *properties,
					t_chars c);
char			*ft_itoa_printf(long long n, t_properties *properties);
t_properties	*parse_format(const char **format, va_list *args);
void			handle_pointer(t_stringlist **string, t_properties *prop,
					va_list *args);
void			handle_hex(t_stringlist **string, t_properties *properties,
					va_list *args);
void			handle_uint(t_stringlist **string, t_properties *properties,
					va_list *args);
void			handle_int(t_stringlist **string, t_properties *properties,
					va_list *args);
void			handle_string(t_stringlist **string, t_properties *prop,
					va_list *args);
void			handle_char(t_stringlist **string, t_properties *properties,
					va_list *args);
void			handle_percent(t_stringlist **string);
int				print_string(int fd, t_stringlist **string);

#endif
