/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:47:21 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:45:54 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stringlist.h>

static void	strlist_delete_content(void *content)
{
	t_strbuf	*c;

	c = (t_strbuf *)content;
	free(c->buf);
	free(c);
}

/*
	* This one doesn't have an assertion for *str being NULL because
	* free(NULL) is also valid
*/
void	stringlist_clear(t_stringlist **str)
{
	assert(str != NULL);
	if (*str != NULL)
	{
		ft_lstclear(&((*str)->buffers), &strlist_delete_content);
		free(*str);
		*str = NULL;
	}
}

t_stringlist	*stringlist_append(t_stringlist *str, char *new, size_t length)
{
	t_strbuf		*strbuf;
	t_list			*strlist;
	t_stringlist	*string;

	assert(new != NULL);
	strbuf = (t_strbuf *)ft_calloc(1, sizeof(t_strbuf));
	if (strbuf == NULL)
		return (stringlist_clear(&str), free(new), NULL);
	strbuf->buf = new;
	strbuf->length = length;
	strlist = ft_lstnew(strbuf);
	if (strlist == NULL)
		return (free(strbuf->buf), free(strbuf), stringlist_clear(&str), NULL);
	if (str != NULL)
	{
		ft_lstadd_front(&(str->buffers), strlist);
		str->total_length += length;
		return (str);
	}
	string = (t_stringlist *)ft_calloc(1, sizeof(t_string));
	if (string == NULL)
		return (free(strbuf->buf), free(strbuf), free(strlist), NULL);
	string->buffers = strlist;
	string->total_length = length;
	return (string);
}

char	*stringlist_get(const t_stringlist *str)
{
	char		*string;
	t_strbuf	*content;
	t_list		*tmp;
	size_t		i;
	size_t		j;

	assert(str != NULL);
	string = malloc(str->total_length + 1);
	if (string == NULL)
		return (NULL);
	string[str->total_length] = '\0';
	tmp = (t_list *)str->buffers;
	i = 0;
	while (tmp != NULL)
	{
		j = 0;
		content = (t_strbuf *)tmp->content;
		while (j < content->length)
			string[str->total_length - i++ - 1] = content->buf[content->length
				- j++ - 1];
		tmp = tmp->next;
	}
	return (string);
}

char	**get_array(t_stringlist *str)
{
	char		**splitted;
	t_list		*cur;
	t_strbuf	*content;
	size_t		size;
	ssize_t		i;

	assert(str != NULL);
	size = ft_lstsize(str->buffers);
	splitted = ft_calloc(size + 1, sizeof(char *));
	if (splitted == NULL)
		return (stringlist_clear(&str), NULL);
	cur = str->buffers;
	i = size - 1;
	while (i >= 0)
	{
		content = (t_strbuf *)cur->content;
		splitted[i] = malloc(content->length + 1);
		if (splitted[i] == NULL)
			return (stringlist_clear(&str), NULL);
		ft_strlcpy(splitted[i], content->buf, content->length + 1);
		cur = cur->next;
		i--;
	}
	return (splitted);
}
