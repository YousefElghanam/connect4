#include "connect4.h"
#include "libft/libft.h"

static void check_columns(t_data *data, long col);
static void fill_columns_to_check(t_data *data);

t_ai_result ai_turn(t_data *data, long depth) {
  fill_columns_to_check(data);

  t_ai_result best_result;
  best_result.best_col = -1;
  best_result.best_depth = depth;
  best_result.win_conditions = 0;

  t_ai_result cur_result = best_result;

  for (long i = 0; i < data->col_count; i++) {
    if (data->columns_to_check[i]) {
      cur_result.win_conditions = 0;
      cur_result.best_col = i;
      if (best_result.best_col == -1) {
        best_result.best_col = i;
      }
      push_coin(i, data);
      if (check_grid_alg(data)) {
        pop_coin(i, data);
        if (data->state == PLAYER_TURN) {
          return (best_result);
        } else if (data->state == AI_TURN) {
          cur_result.win_conditions++;
          continue;
        }
      }
      else if (depth < 5) {
        data->state = !data->state;
        cur_result = ai_turn(data, depth + 1);
        if (cur_result.best_depth > best_result.best_depth ||
            (cur_result.best_depth == best_result.best_depth &&
             cur_result.win_conditions > best_result.win_conditions)) {
          best_result = cur_result;
          best_result.best_col = i;
        }
        data->state = !data->state;
      }
      pop_coin(i, data);
    }
  }

  return (best_result);
}

static void fill_columns_to_check(t_data *data) {
  ft_bzero(data->columns_to_check, data->col_count * sizeof(bool));
  for (long col = 0; col < data->col_count; col++) {
    if (data->grid[0][col] != EMPTY) {
      continue;
    }

    check_columns(data, col);
  }
}

static void check_columns(t_data *data, long col) {
    for (long offset = 0; offset < 4; offset++) {
      for (long row = 0; row < data->row_count; row++) {
        if (col - offset >= 0 && data->grid[row][col - offset]) {
          data->columns_to_check[col] = true;
          return;
        }

        if (col + offset < data->col_count && data->grid[row][col + offset]) {
          data->columns_to_check[col] = true;
          return;
        }
      }
    }
}
