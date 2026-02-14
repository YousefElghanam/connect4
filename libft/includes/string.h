/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:38:40 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:38:41 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

# ifndef MIN_ALLOC_SIZE
#  define MIN_ALLOC_SIZE 32
# endif

typedef struct s_string
{
	size_t	max_size;
	size_t	length;
	char	buf[];
}			t_string;

#endif
