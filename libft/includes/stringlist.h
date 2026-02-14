/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:38:43 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:42:24 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGLIST_H
# define STRINGLIST_H 

# include "list.h"
# include <stddef.h>

typedef struct s_strbuf
{
	char	*buf;
	size_t	length;
}			t_strbuf;

typedef struct s_stringlist
{
	t_list	*buffers;
	size_t	total_length;
}			t_stringlist;
#endif
