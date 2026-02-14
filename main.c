#include "connect4.h"
#include "libft/includes/libft.h"
#include <stdatomic.h>

void	print_grid(t_data *data)
{
	long	rows;
	long	cols;

	rows = 0;
	cols = 0;
	while (cols < data->col_count) {
		if (cols < 9)
			ft_dprintf(1, " %ld", cols + 1);
		else
			ft_dprintf(1, "%ld", cols + 1);
		cols++;
	}
	ft_dprintf(1, "\n");
	while (rows < data->row_count)
	{
		cols = 0;
		while (cols < data->col_count)
		{
			if (data->grid[rows][cols] == RED)
				ft_dprintf(1, "\033[41m  \033[0m");
			else if (data->grid[rows][cols] == BLUE)
				ft_dprintf(1, "\033[44m  \033[0m");
			else if (data->grid[rows][cols] == EMPTY)
				ft_dprintf(1, "\033[47m  \033[0m");
			cols++;
		}
		ft_dprintf(1, "\n");
		rows++;
	}
}

bool	game_over(const t_data *data) {
	if (data->state == ABORT) {
		ft_dprintf(1, "ABORTED\n");
		return (true);
	}
	if (data->state == AI_WIN) {
		ft_dprintf(1, "AI WON\n");
		return (true);
	}
	if (data->state == PLAYER_WIN) {
		ft_dprintf(1, "PLAYER WON\n");
		return (true);
	}
	if (data->state == DRAW) {
		ft_dprintf(1, "DRAW\n");
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	data;
	long row;

	if (!validate_args(argc, argv))
		return (1);
	if (!init_data(&data, argv))
		return (1);
	print_grid(&data);
	data.state = PLAYER_TURN;
	while (!game_over(&data)) {
		if (data.state == PLAYER_TURN) {
			prompt_player(&data);
		}
		else if (data.state == AI_TURN)
		{
			t_ai_result result = ai_turn(&data, 0);
			row = push_coin(result.best_col, &data);
			if (check_cell(row, result.best_col, &data)) {
				data.state = AI_WIN;
			} else {
				data.state = PLAYER_TURN;
			}
		}
		print_grid(&data);
	}
	free_data(&data);
}
