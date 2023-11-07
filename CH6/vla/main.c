#include <stddef.h>
int matrix_sum(size_t rows, size_t cols, int m[rows][cols]){
  int total = 0;
  for (size_t r = 0; r < rows; r++){
    for (size_t c =0; c < cols; c++){
      total += m[r][c];
    }
  }
  return total;
}
