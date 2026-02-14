/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:00:49 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 17:01:20 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>

void	ft_free(void **ptr)
{
	assert(ptr != NULL);
	free(*ptr);
	*ptr = NULL;
}
