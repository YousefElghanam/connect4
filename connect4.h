#ifndef CONNECT_4_H
# define CONNECT_4_H

# define ROW_LIMIT 50
# define COL_LIMIT 50

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef enum e_state
{
	PLAYER_TURN,
	AI_TURN,
	PLAYER_WIN,
	AI_WIN,
	DRAW,
	ABORT
}	t_state;

typedef struct	s_data
{
	long	row_count;
	long	col_count;
	int **grid;
	t_state state;
}	t_data;

#endif /* CONNECT_4_H */
