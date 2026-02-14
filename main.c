#include "connect4.h"
#include "libft/libft.h"
#include <time.h>

bool	validate_args(int argc, char **argv)
{
	long	rows;
	long	cols;

	if (argc != 3)
		return (ft_printf(2, "Accepts only exactly 2 arguments: \
./connect4 ROWS COLS\n"), false);
	rows = ft_atoi_but_better(argv[1]);
	cols = ft_atoi_but_better(argv[2]);
	if (rows == (long)INT_MAX + 1 || rows < ROW_MIN || rows > ROW_MAX)
		return (ft_printf(2, "Invalid row count. [%d - %d]\n", ROW_MIN, ROW_MAX), false);
	if (cols == (long)INT_MAX + 1 || cols < COL_MIN || cols > COL_MAX)
		return (ft_printf(2, "Invalid col count. [%d - %d]\n", COL_MIN, COL_MAX), false);
	return (true);
}

static void ft_free(void **ptr) {
	free(*ptr);
	*ptr = NULL;
}

bool	init_data(t_data *data, char **argv)
{
	data->row_count = ft_atoi_but_better(argv[1]);
	data->col_count = ft_atoi_but_better(argv[2]);
	data->columns_to_check = ft_calloc(data->col_count, sizeof(bool));
	if (!data->columns_to_check) {
		return (ft_printf(2, "Memory allocation failed\n"), false); 
	}
	data->grid = ft_calloc(data->row_count, sizeof(int *));
	if (!data->grid) {
		ft_free((void **)&data->columns_to_check);
		return (ft_printf(2, "Memory allocation failed\n"), false); 
	}
	for (long i = 0; i < data->row_count; i++) {
		data->grid[i] = ft_calloc(data->col_count, sizeof(int));
		if (!data->grid[i]) {
			for (long j = 0; j < i; j++) {
				free(data->grid[i]);
			}
			ft_free((void **)&data->grid);
			ft_free((void **)&data->columns_to_check);
			return (ft_printf(2, "Memory allocation failed\n"), false); 
		}
	}
	srand(time(0));
	data->state = rand() % 2;
	ft_printf(1, "init state to %d\n", data->state);
	return (true);
}

void	print_grid(t_data *data)
{
	long	rows;
	long	cols;

	rows = 0;
	while (rows < data->row_count)
	{
		cols = 0;
		while (cols < data->col_count)
		{
			ft_printf(1, "%d\t", data->grid[rows][cols]);
			cols++;
		}
		ft_printf(1, "\n");
		rows++;
	}
}

void	free_data(t_data *data)
{
	if (data->grid) {
		for (long i = 0; i < data->row_count; i++) {
			free(data->grid[i]);
		}
		free(data->grid);
	}
}

bool game_over(const t_data *data) {
	(void)data;
	// Print result if return value is true
	if (data->state == ABORT) {
		ft_printf(1, "ABORTED\n");
		return (true);
	}
	if (data->state == AI_WIN) {
		ft_printf(1, "AI WON\n");
		return (true);
	}
	if (data->state == PLAYER_WIN) {
		ft_printf(1, "PLAYER WON\n");
		return (true);
	}
	if (data->state == DRAW) {
		ft_printf(1, "DRAW\n");
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
		return (1);
	if (!init_data(&data, argv))
		return (1);
	print_grid(&data);
	data.state = PLAYER_TURN;
	while (!game_over(&data)) {
		if (data.state == PLAYER_TURN) {
			prompt_player(&data);
			data.state = AI_TURN;
		}
		else
		{
			// AI
			t_ai_result result = ai_turn(&data, 0);
			ft_printf(1, "Best column: %d\n", result.best_col);
			data.state = PLAYER_TURN;
		}
	}
	free_data(&data);
}
