#include "connect4.h"
#include "libft/libft.h"

static void check_columns(t_data *data, long col);
static void fill_columns_to_check(t_data *data);

typedef struct s_ai_result {
  long best_col;
  long best_depth;
  long win_conditions;
} t_ai_result;

t_ai_result ai_turn(t_data *data, long depth) {
  fill_columns_to_check(data);

  t_ai_result best_result;
  best_result.best_col = 0;
  best_result.best_depth = depth;
  best_result.win_conditions = 0;

  t_ai_result cur_result = best_result;

  for (long i = 0; i < data->col_count; i++) {
    if (data->columns_to_check[i]) {
      cur_result.win_conditions = 0;
      cur_result.best_col = i;
      // put_value in spot
      if (game_over(data)) {
        // remove item put in that spot
        if (data->state == PLAYER_TURN) {
          return (best_result);
        } else if (data->state == AI_TURN) {
          cur_result.win_conditions++;
        }
      }
      else if (depth < 10) {
        data->state = !data->state;
        cur_result = ai_turn(data, depth + 1);
        if (cur_result.best_depth > best_result.best_depth ||
            (cur_result.best_depth == best_result.best_depth &&
             cur_result.win_conditions > best_result.win_conditions)) {
          best_result = cur_result;
        }
        data->state = !data->state;
      }
      // remove item put in that spot
    }
  }

  return (best_result);
}

static void fill_columns_to_check(t_data *data) {
  ft_bzero(data->columns_to_check, data->col_count * sizeof(bool));
  for (long col = 0; col < data->col_count; col++) {
    if (data->grid[col] != 0) {
      continue;
    }

    check_columns(data, col);
  }
}

static void check_columns(t_data *data, long col) {
    for (long offset = 0; offset < 4; offset++) {
      for (long row = 0; row < data->row_count; row++) {
        if (col - offset >= 0 && data->grid[col - offset][row]) {
          data->columns_to_check[col] = true;
          return;
        }

        if (col + offset < data->col_count && data->grid[col + offset][row]) {
          data->columns_to_check[col] = true;
          return;
        }
      }
    }
}
