#include "sudoku-solver.h"

bool row_contains(std::vector<std::vector<int>>& field, int row, int val) {
  // check if row contains val

  bool contains = false;
  for (int i = 0; i < 9; ++i) {
    if (field[row][i] == val) {
      contains = true;
    }
  }

  return contains;
}

bool col_contains(std::vector<std::vector<int>>& field, int col, int val) {
  // check if column contains val

  bool contains = false;
  for (int i = 0; i < 9; ++i) {
    if (field[i][col] == val) {
      contains = true;
    }
  }

  return contains;
}

bool blk_contains(std::vector<std::vector<int>>& field, int row, int col,
                  int val) {
  // check if block contains val

  bool contains = false;
  int blk_row = row / 3 * 3;
  int blk_col = col / 3 * 3;

  for (int i = blk_row; i < blk_row + 3; ++i) {
    for (int j = blk_col; j < blk_col + 3; ++j) {
      if (field[i][j] == val) {
        contains = true;
      }
    }
  }

  return contains;
}

std::vector<int> valid_values(std::vector<std::vector<int>>& field, int row,
                              int col) {
  // find valid values for cell

  std::vector<int> values;
  for (int val = 1; val <= 9; ++val) {
    if (!row_contains(field, row, val) && !col_contains(field, col, val) &&
        !blk_contains(field, row, col, val)) {
      values.push_back(val);
    }
  }

  return values;
}

void backtrack(std::vector<std::vector<int>>& field, int row, int col,
               std::pair<size_t, std::vector<std::vector<int>>>& res) {
  // find all solutions for sudoku by backtracking

  if (row == 9) {
    row = 0;
    ++col;
    if (col == 9) {
      // if all cells are filled then solution was found
      ++res.first;
      res.second = field;
      return;
    }
  }

  if (field[row][col] > 0) {

    // if current cell is not empty, skip it
    backtrack(field, row + 1, col, res);

  } else {

    // if current cell is empty, try all valid values
    std::vector<int> values = valid_values(field, row, col);

    if (values.empty()) {
      // if there are no valid values go back
      return;
    }

    for (int val : values) {
      field[row][col] = val;
      backtrack(field, row + 1, col, res);
    }

    // after trying all values reset cell to 0
    field[row][col] = 0;
  }
}

std::pair<size_t, std::vector<std::vector<int>>>
sudoku_solve(const std::vector<std::vector<int>>& field) {
  // return N of solutions and one of them

  // create copy of original field
  std::vector<std::vector<int>> field_copy = field;
  // create a variable for result
  std::pair<size_t, std::vector<std::vector<int>>> res;
  res.first = 0;
  backtrack(field_copy, 0, 0, res);

  return res;
}