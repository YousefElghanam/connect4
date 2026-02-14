#include "connect4.h"

static bool	valid_line(char *line) {
	if (!*line || *line == '\n') {
		return (false);
	}
	for (size_t i = 0; i < ft_strlen(line) - 1; i++) {
		if (!ft_isdigit(line[i]))
			return (false);
	}
	return (true);
}

void	prompt_player(t_data *data) {
	char	*line;
	long	col;
	long	row;

	ft_printf(1, "Enter col number\n");
	while (true) {
		line = get_next_line(0);
		if (!line) {
			data->state = ABORT;
			free(line);
			return ;
		}
		if (!valid_line(line)) {
			ft_printf(1, "Invalid input. Please enter a valid number\n");
			free(line);
			continue ;
		}
		col = ft_atoi_but_better(line);
		free(line);
		if (col == (long)INT_MAX + 1 || col < 1 || col > data->col_count) {
			ft_printf(1, "Invalid. Please enter column number [1 - %d]\n", ROW_MAX);
			continue ;
		}
		row = push_coin(col - 1, data);
		if (row == -1)
			continue ;
		if (check_cell(row, col - 1, data))
			data->state = PLAYER_WIN;
		else
			data->state = AI_TURN;
		return ;
	}
}
