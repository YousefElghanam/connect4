#include "connect4.h"
#include "libft/libft.h"

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

bool	col_full(long col, t_data *data) {
	if (data->grid[0][col] != EMPTY) {
		return (true);
	}
	return (false);
}

bool	col_empty(long col, t_data *data) {
	if (data->grid[data->row_count - 1][col] == EMPTY) {
		return (true);
	}
	return (false);
}

// bool	pop_coin(long col, t_data *data) {
// 	return (false);
// }

bool	push_coin(long col, t_data *data) {
	if (col_full(col, data)) {
		return (true);
	}
	return (false);
}

void	prompt_player(t_data *data) {
	char	*line;
	long	col_num;

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
		col_num = ft_atoi_but_better(line);
		// ft_printf(1, "col_num is %d\n", col_num);
		if (col_num == (long)INT_MAX + 1 || col_num < 1 || col_num > data->col_count + 1) {
			ft_printf(1, "Invalid. Please enter column number [%d - %d]\n", ROW_MIN, ROW_MAX);
			free(line);
			continue ;
		}
		free(line);
		return ;
	}
}
