/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@students.42vienna.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:47:00 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 02:39:16 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

static char	*get_next_word(const char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	word = malloc(++i);
	if (word == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(word, s, i);
	return (word);
}

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			words++;
		}
		i++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**splitted;
	size_t	word_index;
	size_t	i;

	assert(s != NULL);
	splitted = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	word_index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			splitted[word_index] = get_next_word(s + i, c);
			if (splitted[word_index] == NULL)
			{
				free_array((void ***)&splitted, free);
				return (NULL);
			}
			word_index++;
		}
		i++;
	}
	return (splitted);
}
