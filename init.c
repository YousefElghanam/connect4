#include "libft/includes/libft.h"
#include "connect4.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

static bool numeric_check(const char *arg);

bool	init_data(t_data *data, char **argv)
{
	data->row_count = ft_atoi(argv[1]);
	data->col_count = ft_atoi(argv[2]);
	data->columns_to_check = ft_calloc(data->col_count, sizeof(bool));
	if (!data->columns_to_check) {
		return (ft_dprintf(2, "Memory allocation failed\n"), false); 
	}
	data->grid = ft_calloc(data->row_count, sizeof(int *));
	if (!data->grid) {
		ft_free((void **)&data->columns_to_check);
		return (ft_dprintf(2, "Memory allocation failed\n"), false); 
	}
	for (long i = 0; i < data->row_count; i++) {
		data->grid[i] = ft_calloc(data->col_count, sizeof(int));
		if (!data->grid[i]) {
			for (long j = 0; j < i; j++) {
				free(data->grid[i]);
			}
			ft_free((void **)&data->grid);
			ft_free((void **)&data->columns_to_check);
			return (ft_dprintf(2, "Memory allocation failed\n"), false); 
		}
	}
	data->state = rand() % 2;
	return (true);
}

void	free_data(t_data *data)
{
	if (data->grid) {
		for (long i = 0; i < data->row_count; i++) {
			free(data->grid[i]);
		}
		free(data->grid);
	}
	free(data->columns_to_check);
}

bool	validate_args(int argc, char **argv)
{
	long	rows;
	long	cols;

	if (argc != 3)
		return (ft_dprintf(2, "Accepts only exactly 2 arguments: \
./connect4 ROWS COLS\n"), false);
	if (!numeric_check(argv[1]) || !numeric_check(argv[2])) {
		return (ft_dprintf(2, "Arguments must be numeric\n"), false);
	}
	rows = ft_atoi(argv[1]);
	cols = ft_atoi(argv[2]);
	if (rows < ROW_MIN || rows > ROW_MAX)
		return (ft_dprintf(2, "Invalid row count. [%d - %d]\n", ROW_MIN, ROW_MAX), false);
	if (cols < COL_MIN || cols > COL_MAX)
		return (ft_dprintf(2, "Invalid col count. [%d - %d]\n", COL_MIN, COL_MAX), false);
	return (true);
}

static bool numeric_check(const char *arg) {
	while (*arg) {
		if (!ft_strchr("0123456789+-", *arg)) {
			return (false);
		}
		arg++;
	}

	return (true);
}
