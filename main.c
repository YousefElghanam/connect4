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
	if (rows == (long)INT_MAX + 1 || rows < 6 || rows > ROW_LIMIT)
		return (ft_printf(2, "Invalid row count. [6 - %d]\n", ROW_LIMIT), false);
	if (cols == (long)INT_MAX + 1 || cols < 7 || cols > COL_LIMIT)
		return (ft_printf(2, "Invalid col count. [7 - %d]\n", COL_LIMIT), false);
	return (true);
}

bool	init_data(t_data *data, char **argv)
{
	data->row_count = ft_atoi_but_better(argv[1]);
	data->col_count = ft_atoi_but_better(argv[2]);
	data->grid = ft_calloc(data->row_count, sizeof(int *));
	if (!data->grid)
		return (ft_printf(2, "Memory allocation failed\n"), false); 
	for (long i = 0; i < data->row_count; i++) {
		data->grid[i] = ft_calloc(data->col_count, sizeof(int));
		if (!data->grid[i]) {
			for (long j = 0; j < i; j++) {
				free(data->grid[i]);
			}
			free(data->grid);
			data->grid = NULL;
			return (ft_printf(2, "Memory allocation failed\n"), false); 
		}
	}
	srand(time(0));
	data->state = rand() % 2;
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
	while (game_over(&data)) {
		if (data.state == PLAYER_TURN) {
			// prompt for input
			data.state = AI_TURN;
		} else {
			// AI
			data.state = PLAYER_TURN;
		}
	}
	free_data(&data);
}
