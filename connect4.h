#ifndef CONNECT_4_H
# define CONNECT_4_H

# define ROW_MIN 6
# define ROW_MAX 50
# define COL_MIN 7
# define COL_MAX 50

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef enum e_pos_state
{
	BLUE,
	RED,
	EMPTY
}	t_pos_state;

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
	int		**grid;
	t_state	state;
	bool	*columns_to_check;
}	t_data;

typedef struct s_ai_result {
  long best_col;
  long best_depth;
  long win_conditions;
} t_ai_result;

bool	game_over(const t_data *data);
void	prompt_player(t_data *data);
t_ai_result ai_turn(t_data *data, long depth);

#endif /* CONNECT_4_H */
