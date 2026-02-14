#include "connect4.h"

// bool	horizontal_check(long row, long col, const t_data *data) {
// 	long	color;

// 	color = data->grid[row][col];
// 	for (long i = 1; i < MATCHES_TO_WIN && col + i < data->col_count; i++) {
// 		if (data->grid[row][col + i] != color)
// 			return (false);
// 	}
// 	ft_printf(1, "horizontal checked true\n");
// 	return (true);
// }

// bool	vertical_check(long row, long col, const t_data *data) {
// 	long	color;

// 	color = data->grid[row][col];
// 	for (long i = 1; i < MATCHES_TO_WIN && row + i < data->row_count; i++) {
// 		if (data->grid[row + i][col] != color)
// 			return (false);
// 	}
// 	ft_printf(1, "vertical checked true\n");
// 	return (true);
// }

bool	in_bound(long row, long col, t_data *data) {
	if (row >= 0 && row < data->row_count
		&& col >= 0 && col < data->col_count)
			return (true);
	return (false);
}

bool	win_right(long row, long col, t_data *data) {
	long	i;
	int		color;

	i = 1;
	color = data->grid[row][col];
	while (i < MATCHES_TO_WIN) {
		if (!in_bound(row, col + i, data))
			return (false);
		if (data->grid[row][col + i] != color)
			return (false);
		i++;
	}
	return (true);
}

bool	win_left(long row, long col, t_data *data) {
	long	i;
	int		color;

	i = 1;
	color = data->grid[row][col];
	while (i < MATCHES_TO_WIN) {
		if (!in_bound(row, col - i, data))
			return (false);
		if (data->grid[row][col - i] != color)
			return (false);
		i++;
	}
	return (true);
}

bool	win_up(long row, long col, t_data *data) {
	long	i;
	int		color;

	i = 1;
	color = data->grid[row][col];
	while (i < MATCHES_TO_WIN) {
		if (!in_bound(row - i, col, data))
			return (false);
		if (data->grid[row - i][col] != color)
			return (false);
		i++;
	}
	return (true);
}

bool	win_down(long row, long col, t_data *data) {
	long	i;
	int		color;

	i = 1;
	color = data->grid[row][col];
	while (i < MATCHES_TO_WIN) {
		if (!in_bound(row + i, col, data))
			return (false);
		if (data->grid[row + i][col] != color)
			return (false);
		i++;
	}
	return (true);
}

bool	check_cell(long row, long col, t_data *data) {
	if (win_right(row, col, data)
		|| win_left(row, col, data)
		|| win_up(row, col, data)
		|| win_down(row, col, data))
		return (true);
	return (false);
}

// void	check_grid(t_data *data) {
// 	for (long row = 0; row < data->row_count; row++) {
// 		for (long col = 0; col < data->col_count; col++) {
// 			if (data->grid[row][col] == EMPTY)
// 				continue ;
// 			if (check_cell(row, col, data)) {
// 				if (data->state == PLAYER_TURN)
// 					data->state = AI_WIN;
// 				else if (data->state == AI_TURN)
// 					data->state = PLAYER_WIN;
// 			}
// 			if (data->state != AI_TURN && data->state != PLAYER_TURN)
// 				return ;
// 		}
// 	}
// }

// bool	check_grid_alg(t_data *data) {
// 	for (long row = 0; row < data->row_count; row++) {
// 		for (long col = 0; col < data->col_count; col++) {
// 			if (data->grid[row][col] == EMPTY)
// 				continue ;
// 			if (check_cell(row, col, data))
// 				return (true);
// 		}
// 	}
// 	return (false);
// }
