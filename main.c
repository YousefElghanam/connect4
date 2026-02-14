#include "connect4.h"
#include "libft/libft.h"

bool	validate_args(int argc, char **argv)
{
	long	rows;
	long	cols;

	if (argc != 3)
		return (ft_printf(2, "Accepts only exactly 2 arguments: \
./connect4 ROWS COLS\n"), false);
	rows = ft_atoi_but_better(argv[1]);
	cols = ft_atoi_but_better(argv[2]);
	if (rows == (long)INT_MAX + 1 || rows < 6 || rows > 50)
		return (ft_printf(2, "Invalid row count. [6 - 50]\n"), false);
	if (cols == (long)INT_MAX + 1 || cols < 7 || cols > 50)
		return (ft_printf(2, "Invalid col count. [7 - 50]\n"), false);
	return (true);
}

bool	init_data(t_data *data, char **argv)
{
	data->row_count = ft_atoi_but_better(argv[1]);
	data->col_count = ft_atoi_but_better(argv[2]);
	data->grid = ft_calloc(data->row_count, data->col_count);
	if (!data->grid)
		return (ft_printf(2, "Memory allocation failed\n"), false); 
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
			ft_printf(1, "%d\t", data->grid[rows + cols]);
			cols++;
		}
		ft_printf(1, "\n");
		rows++;
	}
}

void	free_data(t_data *data)
{
	free(data->grid);
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (!validate_args(argc, argv))
		return (1);
	if (!init_data(&data, argv))
		return (1);
	print_grid(&data);
	free_data(&data);
}
