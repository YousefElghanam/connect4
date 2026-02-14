/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:06:56 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/11/27 14:45:38 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "list.h"
# include "string.h"
# include "stringlist.h"
# include "unistd.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

// ctype
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

// stdlib
void			free_array(void ***array, void (*f)(void *));
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_itoa(int n);
void			ft_free(void **ptr);

// string
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// stringlist
char			*stringlist_get(const t_stringlist *str);
t_stringlist	*stringlist_append(t_stringlist *str, char *new, size_t length);
void			stringlist_clear(t_stringlist **str);

// string
t_string		*string_create(const char *input);
t_string		*string_create_len(const char *input, size_t length);
t_string		*string_join(const t_string *first, const t_string *second);
bool			string_append(t_string **string, const t_string *append);
t_string		**string_split(const t_string *string, const char *charset);
t_string		*string_substr(const t_string *string, size_t pos,
					size_t count);

// mem
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

// put
ssize_t			ft_putchar_fd(char c, int fd);
ssize_t			ft_putstr_fd(const char *s, int fd);
ssize_t			ft_putendl_fd(const char *s, int fd);
ssize_t			ft_putnbr_fd(int n, int fd);

// list
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// GNL
char			*get_next_line(int fd);

// ft_printf

int				ft_printf(const char *format, ...) __attribute__((format(printf,
							1, 2)));
int				ft_dprintf(int fd, const char *format,
					...) __attribute__((format(printf, 2, 3)));

// misc
uint64_t		next_power_of_two(uint64_t n);
#endif
