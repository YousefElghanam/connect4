#include "connect4.h"
#include "libft/includes/libft.h"

bool	in_bound(long row, long col, t_data *data) {
	if (row >= 0 && row < data->row_count
		&& col >= 0 && col < data->col_count)
			return (true);
	return (false);
}

bool	win_neg_diagonal(long row, long col, t_data *data) {
	int		color;
	long	matches;

	color = data->grid[row][col];
	matches = 1;
	while (matches < MATCHES_TO_WIN
			&& in_bound(row + matches, col + matches, data)
			&& data->grid[row + matches][col + matches] == color) {
				matches++;
				ft_dprintf(1, "neg dia matches: %d\n", (int)matches);
			}
	while (matches < MATCHES_TO_WIN
			&& in_bound(row - matches, col - matches, data)
			&& data->grid[row - matches][col - matches] == color) {
				matches++;
				ft_dprintf(1, "neg dia matches: %d\n", (int)matches);
			}
	return (matches == MATCHES_TO_WIN);
}

bool	win_pos_diagonal(long row, long col, t_data *data) {
	int		color;
	long	matches;

	color = data->grid[row][col];
	matches = 1;
	while (matches < MATCHES_TO_WIN
			&& in_bound(row - matches, col + matches, data)
			&& data->grid[row - matches][col + matches] == color) {
				matches++;
				ft_dprintf(1, "pos dia matches: %d\n", (int)matches);
			}
	while (matches < MATCHES_TO_WIN
			&& in_bound(row + matches, col - matches, data)
			&& data->grid[row + matches][col - matches] == color) {
				matches++;
				ft_dprintf(1, "pos dia matches: %d\n", (int)matches);
			}
	return (matches == MATCHES_TO_WIN);
}

bool	win_horizontal(long row, long col, t_data *data) {
	int		color;
	long	matches;

	color = data->grid[row][col];
	matches = 1;
	while (matches < MATCHES_TO_WIN
			&& in_bound(row, col + matches, data)
			&& data->grid[row][col + matches] == color) {
				matches++;
				ft_dprintf(1, "hor matches: %d\n", (int)matches);
			}
	while (matches < MATCHES_TO_WIN
			&& in_bound(row, col - matches, data)
			&& data->grid[row][col - matches] == color) {
				matches++;
				ft_dprintf(1, "hor matches: %d\n", (int)matches);
			}
	return (matches == MATCHES_TO_WIN);
}

bool	win_vertical(long row, long col, t_data *data) {
	int		color;
	long	matches;

	color = data->grid[row][col];
	matches = 1;
	while (matches < MATCHES_TO_WIN
			&& in_bound(row + matches, col, data)
			&& data->grid[row + matches][col] == color) {
				matches++;
				ft_dprintf(1, "vert matches: %d\n", (int)matches);
			}
	while (matches < MATCHES_TO_WIN
			&& in_bound(row - matches, col, data)
			&& data->grid[row - matches][col] == color) {
				matches++;
				ft_dprintf(1, "vert matches: %d\n", (int)matches);
			}
	return (matches == MATCHES_TO_WIN);
}

bool	check_cell(long row, long col, t_data *data) {
	return (win_horizontal(row, col, data)
			|| win_vertical(row, col, data)
			|| win_pos_diagonal(row, col, data)
			|| win_neg_diagonal(row, col, data));
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
