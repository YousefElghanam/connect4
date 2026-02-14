#include "connect4.h"
#include "libft/libft.h"

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

bool	pop_coin(long col, t_data *data) {
	long	row;

	row = 0;
	if (col_empty(col, data))
		return (ft_printf(2, "Can't pop, column not empty\n"), true);
	while (row < data->row_count && data->grid[row][col] == EMPTY)
		row++;
	// row--;
	if (data->state == PLAYER_TURN || data->state == AI_TURN)
		data->grid[row][col] = EMPTY;
	else
		ft_printf(2, "UNEXPECTED ERROR WHILE TRYING TO POP COIN\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	return (false);
}

bool	push_coin(long col, t_data *data) {
	long	row;

	row = data->row_count - 1;
	while (row >= 0 && data->grid[row][col] != EMPTY) {
		row--;
	}
	if (row == -1)
		return (ft_printf(2, "Can't push, column is full\n"), true);
	// ft_printf(1, "detected empty row at %d\n", (int)row);
	if (data->state == PLAYER_TURN)
		data->grid[row][col] = BLUE;
	else if (data->state == AI_TURN)
		data->grid[row][col] = RED;
	else
		ft_printf(2, "UNEXPECTED ERROR WHILE TRYING TO PUSH COIN\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	return (false);
}
