#ifndef CONNECT_4_H
# define CONNECT_4_H

# define ROW_LIMIT 50
# define COL_LIMIT 50

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct	s_data
{
	long	row_count;
	long	col_count;
	long	*grid;
}	t_data;

#endif /* CONNECT_4_H */
