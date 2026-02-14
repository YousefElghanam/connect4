/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:35:39 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:47:53 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	count_words(const t_string *string, const char *charset);
static void		skip_till_word(const t_string *string, size_t *pos,
					const char *charset);
static t_string	*get_word(const t_string *string, size_t *pos,
					const char *charset);
static bool		is_delim(char c, const char *charset);

t_string	**string_split(const t_string *string, const char *charset)
{
	size_t		word_count;
	t_string	**splitted;
	size_t		pos;
	size_t		i;

	assert(string != NULL);
	assert(charset != NULL);
	word_count = count_words(string, charset);
	splitted = malloc((word_count + 1) * sizeof(t_string *));
	if (!splitted)
		return (NULL);
	pos = 0;
	i = -1;
	while (++i < word_count)
	{
		skip_till_word(string, &pos, charset);
		splitted[i] = get_word(string, &pos, charset);
		if (!splitted[i])
		{
			free_array((void ***)&splitted, free);
			return (NULL);
		}
	}
	splitted[word_count] = NULL;
	return (splitted);
}

static size_t	count_words(const t_string *string, const char *charset)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < string->length)
	{
		if (!is_delim(string->buf[i], charset) && (i == 0
				|| is_delim(string->buf[i - 1], charset)))
			count++;
		i++;
	}
	return (count);
}

static void	skip_till_word(const t_string *string, size_t *pos,
		const char *charset)
{
	while (is_delim(string->buf[*pos], charset))
		(*pos)++;
}

static t_string	*get_word(const t_string *string, size_t *pos,
		const char *charset)
{
	size_t		last;
	size_t		length;
	t_string	*part;

	last = *pos;
	while (!is_delim(string->buf[last], charset) && last < string->length)
		last++;
	length = last - *pos;
	part = string_substr(string, *pos, length);
	*pos = last;
	return (part);
}

static bool	is_delim(char c, const char *charset)
{
	return (ft_strchr(charset, c) != NULL);
}
