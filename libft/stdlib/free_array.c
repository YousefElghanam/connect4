/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgebetsb <bgebetsb@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:34:20 by bgebetsb          #+#    #+#             */
/*   Updated: 2025/03/14 00:35:44 by bgebetsb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void	free_array(void ***array, void (*f)(void *))
{
	void	**tmp;

	assert(array != NULL);
	if (!*array)
		return ;
	tmp = *array;
	while (*tmp)
	{
		f(*tmp);
		tmp++;
	}
	free(*array);
	*array = NULL;
}
