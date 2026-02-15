#ifndef CONNECT_4_H
# define CONNECT_4_H

# define DEBUG 1
# define MATCHES_TO_WIN 4
# define ROW_MIN 6
# define ROW_MAX 42
# define COL_MIN 7
# define COL_MAX 42

# define MAX_RECURSION_DEPTH 5

# include "libft/includes/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef enum e_pos_state
{
	EMPTY = 0,
	BLUE = -1,
	RED = 1
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
}	t_data;

typedef struct s_ai_result {
  long best_depth;
  long win_conditions;
  long lose_conditions;
} t_ai_result;

bool	check_cell(long row, long col, t_data *data);
bool	check_grid_alg(t_data *data);
void	check_grid(t_data *data);
bool	game_over(const t_data *data);
void	prompt_player(t_data *data);
long ai_turn(t_data *data);

bool	col_full(long col, t_data *data);
bool	col_empty(long col, t_data *data);
bool	pop_coin(long col, t_data *data);
long	push_coin(long col, t_data *data);

bool	validate_args(int argc, char **argv);
bool	init_data(t_data *data, char **argv);
void	free_data(t_data *data);

#endif /* CONNECT_4_H */
