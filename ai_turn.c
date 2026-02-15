#include "connect4.h"
#include "libft/includes/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <threads.h>

static void check_columns(t_data *data, bool *columns, long col);
static bool fill_columns_to_check(t_data *data, bool *columns);

inline long __attribute__((always_inline)) evaluate_score(int *window, t_pos_state color) {
  int self_count = 0;
  int opponent_count = 0;
  int empty_count = 0;

  t_pos_state opponent_color = (color == BLUE) ? RED : BLUE;

  if (window[0] == color) {
    self_count++;
  } else if (window[0] == opponent_color) {
    opponent_count++;
  } else {
    empty_count++;
  }
  if (window[1] == color) {
    self_count++;
  } else if (window[1] == opponent_color) {
    opponent_count++;
  } else {
    empty_count++;
  }
  if (window[2] == color) {
    self_count++;
  } else if (window[2] == opponent_color) {
    opponent_count++;
  } else {
    empty_count++;
  }
  if (window[3] == color) {
    self_count++;
  } else if (window[3] == opponent_color) {
    opponent_count++;
  } else {
    empty_count++;
  }

  if (self_count == 4) {
    return 100000;
  } else if (self_count == 3 && empty_count == 1) {
    return 1000;
  } else if (self_count == 2 && empty_count == 2) {
    return 100;
  } else if (opponent_count == 3 && empty_count == 1) {
    return -5000;
  }

  return 0;
}

inline long __attribute__((always_inline)) score(t_data *data, t_pos_state color) {
  int window[4];

  long total_score = 0;

  for (long row = 0; row < data->row_count; row++) {
    for (long col = 0; col < data->col_count; col++) {
      if (col > 3 && col < data->col_count - 3)
        total_score += 5;
      if (col < data->col_count - 3) {
        window[0] = data->grid[row][col];
        window[1] = data->grid[row][col + 1];
        window[2] = data->grid[row][col + 2];
        window[3] = data->grid[row][col + 3];

        total_score += evaluate_score(window, color);
      }

      if (row < data->row_count - 3) {
        window[0] = data->grid[row][col];
        window[1] = data->grid[row + 1][col];
        window[2] = data->grid[row + 2][col];
        window[3] = data->grid[row + 3][col];

        total_score += evaluate_score(window, color);
      }

      if (col < data->col_count - 3 && row < data->row_count - 3) {
        window[0] = data->grid[row][col];
        window[1] = data->grid[row + 1][col + 1];
        window[2] = data->grid[row + 2][col + 2];
        window[3] = data->grid[row + 3][col + 3];

        total_score += evaluate_score(window, color);
      }

      if (col >= 3 && row < data->row_count - 3) {
        window[0] = data->grid[row][col];
        window[1] = data->grid[row + 1][col - 1];
        window[2] = data->grid[row + 2][col - 2];
        window[3] = data->grid[row + 3][col - 3];

        total_score += evaluate_score(window, color);
      }
    }
  }

  return total_score;
}

long ai_turn2(t_data *data, size_t depth, long alpha, long beta, t_pos_state color) {
  bool *columns = malloc(sizeof(bool) * data->col_count);
  if (!columns) {
    return -1;
  }

  bool full = fill_columns_to_check(data, columns);

  if (depth == 0 || full) {
    free(columns);
    if (full) {
      return 0;
    }
    return score(data, color);
  }

  long value = LONG_MIN;
  for (long col = 0; col < data->col_count; col++) {
    if (columns[col]) {
      long row = push_coin(col, data);
      long current_score;
      if (check_cell(row, col, data)) {
          current_score = 10000000;
      } else {
        data->state = !data->state;
        current_score = -ai_turn2(data, depth - 1, -beta, -alpha, -color);
        data->state = !data->state;
      }

      pop_coin(col, data);



      if (current_score > value)
        value = current_score;
      if (value > alpha)
        alpha = value;
      if (alpha >= beta)
        break;
    }
  }

  free(columns);
  return value;
}

long ai_turn(t_data *data) {
  long max_score = LONG_MIN;
  long max_pos = 0;

  bool *columns = malloc(sizeof(bool) * data->col_count);
  if (!columns) {
    return -1;
  }
  fill_columns_to_check(data, columns);
  
  for (long i = 0; i < data->col_count; i++) {
    if (columns[i] || data->first_item) {
      long row = push_coin(i, data);
      
      long current_score;
      if (check_cell(row, i, data)) {
        pop_coin(i, data);
        free(columns);
        return i;
      } else {
        data->state = !data->state;
        current_score = -ai_turn2(data, MAX_RECURSION_DEPTH, LONG_MIN + 1, LONG_MAX, BLUE);
        data->state = !data->state;
      }
      
      pop_coin(i, data);
      
      if (current_score == -1) {
        free(columns);
        return -1;
      } else if (current_score > max_score) {
        max_score = current_score;
        max_pos = i;
      }
    }
  }

  free(columns);
  data->first_item = false;
  
  return max_pos;
}

static bool fill_columns_to_check(t_data *data, bool *columns) {
  bool full = true;

  ft_bzero(columns, data->col_count * sizeof(bool));
  for (long col = 0; col < data->col_count; col++) {
    if (data->grid[0][col] != EMPTY) {
      continue;
    }

    full = false;
    check_columns(data, columns, col);
  }

  return (full);
}

static void check_columns(t_data *data, bool *columns, long col) {
    for (long offset = 0; offset < 4; offset++) {
      for (long row = 0; row < data->row_count; row++) {
        if (col - offset >= 0 && data->grid[row][col - offset]) {
          columns[col] = true;
          return;
        }

        if (col + offset < data->col_count && data->grid[row][col + offset]) {
          columns[col] = true;
          return;
        }
      }
    }
}
