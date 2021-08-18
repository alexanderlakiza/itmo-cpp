#include "field-checker.h"

bool check_cell(const std::vector<std::vector<int>>& field, int row, int col) {
  // check if value in cell is valid

  int val = field[row][col];
  bool valid = true;

  // check row
  for (int i = 0; i < 9; ++i) {
    if (i != col && field[row][i] == val) {
      valid = false;
    }
  }

  // check column
  for (int i = 0; i < 9; ++i) {
    if (i != row && field[i][col] == val) {
      valid = false;
    }
  }

  // check block
  int blk_row = row / 3 * 3;
  int blk_col = col / 3 * 3;
  for (int i = blk_row; i < blk_row + 3; ++i) {
    for (int j = blk_col; j < blk_col + 3; ++j) {
      if (!(i == row && j == col) && field[i][j] == val) {
        valid = false;
      }
    }
  }

  return valid;
}

bool check_field(const std::vector<std::vector<int>>& init_field,
                 const std::vector<std::vector<int>>& solution) {
  // check if solution is correct for given init_field

  bool correct = true;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {

      if (init_field[i][j] == 0) {
        // check all new values
        if (!check_cell(solution, i, j)) {
          correct = false;
        }
      } else {
        // if initial values were changed
        if (init_field[i][j] != solution[i][j]) {
          correct = false;
        }
      }
    }
  }

  return correct;
}
